#include "SceneManager.h"
#include <DxLib.h>
#include "Common/ResourceManager.h"
#include "resourse.h"
#include "Common/Input/InputComfig/InputConfig.h"
#include "Common/ThreadPool.h"
#include "Scene/TitleScene.h"
#include "Scene/GameScene.h"
#include "Common/Input/InputType/Keybord.h"
#include "Common/Input/InputType/Pad.h"

#include "Common/Debug.h"

SceneManager SceneManager::instance_;

int SceneManager::Run(void)
{
	if (!isInit_ || !Init())
	{
		return -1;
	}
	DebugLog("初期化終了");
	while (!ProcessMessage() && !isEnd_)
	{
		// 更新処理
		Update();

		// 描画処理
		Draw();
	}
	return 0;
}

void SceneManager::Draw()
{
	scene_->DrawScene();

	// バックバッファに描画
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();
	scene_->Draw();
	DebugInfoDraw();
	ScreenFlip();
	timeClass_.DeltaTimeEnd();
}

void SceneManager::Update()
{
	timeClass_.DeltaTimeStart();
	//controller_->Update(timeClass_.GetDeltaTime<float>());
	scene_ = scene_->Update(std::move(scene_), timeClass_.GetDeltaTime<float>(), *controller_);
	timeClass_.GameTimeEnd();
}

TimeClass& SceneManager::GetTimeClass(void)
{
	return timeClass_;
}

Random& SceneManager::GetRandomClass(void)
{
	return random_;
}

ThreadPool& SceneManager::GetThredPool(void)
{
	return *threadPool_;
}

ResourceManager& SceneManager::GetResourceManager(void)
{
	return *resourceMnager_;
}


SceneManager::SceneManager():
	isInit_{false}
{
	isInit_ = SystemInit();
}

SceneManager::~SceneManager()
{
	DxLib_End();
}

bool SceneManager::Init(void)
{
	SetChangeScreenModeGraphicsSystemResetFlag(false);

	// あらかじめ作成スクリーンを作成しておく
	SharedRenderTargetHandle tmp;
	lpSceneManager.GetResourceManager().MakeRenderTarget(tmp, ScreenID::Loading, screenSize_<float>, true);
	lpSceneManager.GetResourceManager().MakeRenderTarget(tmp, ScreenID::Transition, screenSize_<float>, true);

	threadPool_->WaitAllTask();

	SetUseASyncLoadFlag(true);
	//scene_ = std::make_unique<Loading>(std::make_unique<GameScene>(), TransitionType::Fade, 1.0f);
	//scene_ = std::make_unique<FadeLoading>(std::make_unique<GameScene>(), 1.0f);
	//scene_ = std::make_unique<FadeLoading>(std::make_unique<TitleScene>(), 1.0f);	DebugLog("シーン作成終了");
	timeClass_.DeltaTimeEnd();
	timeClass_.DeltaTimeStart();
	timeClass_.GameTimeEnd();
	return true;
}

bool SceneManager::SystemInit(void)
{
	isEnd_ = false;
	// メモリーリークチェック用のやつ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	DebugStart(timeClass_);
	SetWindowText(TEXT("アンチマジック"));
	SetWindowIconID(IDI_ICON1);
	SetGraphMode(screenSize_<int>.x, screenSize_<int>.y, 32);
	Set3DSoundOneMetre(128.0f);			// 3D空間の1メートル相当の設定
	ChangeWindowMode(true);

	SetUseDirect3DVersion(DX_DIRECT3D_11);
	bool rtn = DxLib_Init() != -1;
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);

	// dxアーカイブのキーをセット
	SetDXArchiveKeyString(L"data");

	// マウスカーソルの表示をオフに
	SetMouseDispFlag(false);

	// リソース管理クラスを作成
	resourceManager_ = std::make_unique<ResourceManager>();

	// スレッドプールを作成
	threadPool_ = std::make_unique<ThreadPool>(2);


	//InputConfig::Create();

	//if (InputConfig::GetInstance().GetNowType() != -1)
	//{
	//	controller_ = std::make_unique<Pad>(InputConfig::GetInstance().GetNowType());
	//}
	//else
	//{
	//	controller_ = std::make_unique<Keyboard>();
	//}

	// デバッグのセットアップ
	DebugSetUp();
	return rtn;
}
