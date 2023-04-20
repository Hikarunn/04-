#pragma once
#include <memory>
#include "Common/Time.h"
#include "Common/Random.h"
#include "Common/Math.h"

//#define lpSceneManager(SceneManager::GetInstance())

//class Resource

class BaseScene;
class ThreadPool;
class Controller;

class SceneManager
{
public:
	int Run(void);

	void Draw();

	void Update();

	struct SceneManager& GetInstance(void)
	{
		return instance_;
	};


private:
	SceneManager();
	~SceneManager();
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

	bool Init(void);

	bool SystemInit(void);

	static SceneManager instance_;

	bool isInit_;

	bool isEnd_;

	//std::unique_ptr<>

	TimeClass timeClass_;

	Random random_;

	std::unique_ptr<BaseScene>scene_;
};

