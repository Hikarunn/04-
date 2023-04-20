#pragma once
#include <memory>
#include "Common/Time.h"
#include "Common/Random.h"
#include "Common/Math.h"

#define lpSceneManager (SceneManager::GetInstance())
#define Rand (SceneManager::GetInstance().GetRandomClass())
#define Thread (SceneManager::GetInstance().GetThredPool())

//class Resource

class BaseScene;
class ThreadPool;
class Controller;

class SceneManager
{
public:
	/// <summary>
	/// 実行処理
	/// </summary>
	int Run(void);

	void Draw();

	void Update();

	static SceneManager& GetInstance(void)
	{
		return instance_;
	};

	/// <summary>
	/// タイムクラスの取得
	/// </summary>
	TimeClass& GetTimeClass(void);

	/// <summary>
	/// 乱数処理クラスの取得
	/// </summary>
	Random& GetRandomClass(void);

	/// <summary>
	/// スレッドプール
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	ThreadPool& GetThredPool(void);

	/// <summary>
	/// プログラムを終了
	/// </summary>
	/// <param name=""></param>
	void End(void)
	{
		isEnd_ = true;
	}

	// スクリーンサイズ
	template<ValueC C>
	static constexpr Vector2Tmp<C> screenSize_{ 1920, 1080}

private:
	SceneManager();
	~SceneManager();
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name=""></param>
	/// <returns>成功の場合true:失敗の場合false</returns>
	bool Init(void);

	/// <summary>
	/// システム関連の初期化
	/// </summary>
	/// <param name=""></param>
	/// <returns>成功の場合true:失敗の場合false</returns>
	bool SystemInit(void);

	// インスタンス
	static SceneManager instance_;

	// 初期化ができたかどうかのフラグ
	bool isInit_;

	// 終了するかのフラグ
	bool isEnd_;

	//std::unique_ptr<>

	// タイムクラス
	TimeClass timeClass_;

	// ランダムクラス
	Random random_;

	// シーン
	std::unique_ptr<BaseScene> scene_;

	// スレッドプール
	std::unique_ptr<ThreadPool> threadPool_;

	// コントローラー
	std::unique_ptr<Controller> controller_;
};

