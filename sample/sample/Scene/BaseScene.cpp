#include <DxLib.h>
#include "BaseScene.h"
#include "../SceneManager.h"
#include "../Object/ObjectManager.h"
#include "../Common/Camera.h"
#include "../UI/UiManager.h"
#include "../Common/Input/InputType/Keybord.h"
#include "../Common/Input/InputType/Pad.h"

#include "../Common/Debug.h"

BaseScene::BaseScene(ScreenID id, SceneID sceneID):
	screenID_{ id }, nextID_{ sceneID }
{
	lpScene
}

BaseScene::BaseScene(std::unique_ptr<ObjectManager>&& objectManager, ScreenID id,SceneID sceneID):
	screenID_{ id }, nextID_{ sceneID }, objManager_{ std::move(objectManager) }
{
}

BaseScene::~BaseScene()
{
}

void BaseScene::Update(float delta, Controller& controller)
{
}

void BaseScene::Draw(void)
{
}

void BaseScene::DrawScene(void)
{
}

const SceneID BaseScene::GetID(void) const
{
	return SceneID();
}

void BaseScene::Relese(void)
{
}

bool BaseScene::IsLoaded(void)
{
	return false;
}

SceneUptr BaseScene::Update(SceneUptr own, float delta, Controller& controller)
{
	return SceneUptr();
}

void BaseScene::ChangeSceneID(SceneID id)
{
}

void BaseScene::SetMakeSceneFunc(std::function<SceneUptr(SceneUptr)>&& sceneMakeFunc, const SceneID id)
{
}

void BaseScene::Loaded(Controller& controller)
{
}

void BaseScene::AddLoadedFunc(LoadedFunc&& loadFunc)
{
}
