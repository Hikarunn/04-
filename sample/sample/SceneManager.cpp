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
	DebugLog("�������I��");
	while (!ProcessMessage() && !isEnd_)
	{
		// �X�V����
		Update();

		// �`�揈��
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
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
}

Random& SceneManager::GetRandomClass(void)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
}

ThreadPool& SceneManager::GetThredPool(void)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
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
