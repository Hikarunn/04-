#include <DxLib.h>
#include "ResourceManager.h"

#include "Debug.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	imageMap_.clear();
	screenMap_.clear();
	modelMap_.clear();
	soundMap_.clear();
}

void ResourceManager::LoadTexture(SharedGraphicHandle& out, const std::filesystem::path& path, bool isNotRelese)
{
	std::lock_guard < std::mutex> lock{ mutex_ };
	auto key{ std::hash<std::string>()(path.string()) };
	if (imageMap_.contains(key))
	{
		out.SetPtr(imageMap_[key].first);
		return;
	}

	int h{ LoadGraph(path.wstring().c_str()) };
	if (h == -1)
	{
		DebugErrorLog("‰æ‘œ“Ç‚İ‚İ¸”s");
	}
	imageMap_.emplace(key, std::make_pair(std::make_shared<int>(), isNotRelese));
	*imageMap_[key].first = h;
	out.SetPtr(imageMap_[key].first);
}

void ResourceManager::LoadDivTexture(SharedDivGraphicHandle& out, const std::filesystem::path& path, const Vector2& divCount, const Vector2I& divSize, bool isNotRelese)
{
	std::lock_guard < std::mutex> lock{ mutex_ };
	auto key{ std::hash<std::string>()(path.string()) };
	if (imageDivMap_.contains(key))
	{
		out.Set(std::get<0>(imageDivMap_[key]));
		out.SetPtr(std::get<1>(imageDivMap_[key]));
		return;
	}
	auto& vec{ std::get<0>(imageDivMap_[key]) };
	auto& sPtr{ std::get<1>(imageDivMap_[key]) };
	vec.resize(divCount.x * divCount.y);
	sPtr = std::make_shared<int>();
	int h{ LoadGraph(path.wstring().c_str()) };
	if (h == -1)
	{
		DebugErrorLog("‰æ‘œ“Ç‚İ‚İ¸”s");
	}
	std
	out.SetPtr(sPtr);
}

void ResourceManager::LoadModelTexture(SharedGraphicHandle& out, const std::filesystem::path& path, bool isNotRelese)
{
	std::lock_guard < std::mutex> lock{ mutex_ };
	auto key{ std::hash<std::string>()(path.string()) };
	if (imageMap_.contains(key))
	{
		
		out.SetPtr(imageMap_[key].first);
		return;
	}

	int h{ MV1LoadTexture(path.wstring().c_str()) };
	if (h == -1)
	{
		DebugErrorLog("‰æ‘œ“Ç‚İ‚İ¸”s");
	}
	imageMap_.emplace(key, std::make_pair(std::make_shared<int>(), isNotRelese));
	*imageMap_[key].first = h;
	out.SetPtr(imageMap_[key].first);
}

void ResourceManager::Remove(SharedGraphicHandle& handle)
{
}

void ResourceManager::Remove(SharedDivGraphicHandle& handle)
{
}

void ResourceManager::MakeRenderTarget(SharedRenderTargetHandle& out, const ScreenID id, const Vector2& size, bool alpha, bool isNotRelese)
{
}

void ResourceManager::Remove(const ScreenID id)
{
}

void ResourceManager::LoadModel(SharedModelHandle& out, const std::filesystem::path& path, bool isNotRelese)
{
}

void ResourceManager::RemoveModel(const int handle)
{
}

void ResourceManager::LoadSound(SharedSoundHandle&& out, const std::filesystem::path& path, bool isNotRelese)
{
}

void ResourceManager::RemoveSound(const int handle)
{
}

void ResourceManager::Loaded(void)
{
}
