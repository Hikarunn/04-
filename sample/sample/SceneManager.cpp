#include "SceneManager.h"
#include <DxLib.h>

#include "Common/Input/InputComfig/InputConfig.h"
#include "Common/ThreadPool.h"
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
	scene_->
}

void SceneManager::Update()
{
}

TimeClass& SceneManager::GetTimeClass(void)
{
	// TODO: return ステートメントをここに挿入します
}

Random& SceneManager::GetRandomClass(void)
{
	// TODO: return ステートメントをここに挿入します
}

ThreadPool& SceneManager::GetThredPool(void)
{
	// TODO: return ステートメントをここに挿入します
}

SceneManager::~SceneManager()
{
}

bool SceneManager::Init(void)
{
	return false;
}

bool SceneManager::SystemInit(void)
{
	return false;
}
