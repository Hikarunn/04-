#pragma once
#include <filesystem>
#include <map>
#include <mutex>
#include <list>
#include <tuple>
#include "ScreenID.h"

class ResourceManager
{
	using HandleFlagPair = std::pair<std::shared_ptr<int>, bool>;
	using HandleMap = std::map<std::uint64_t, HandleFlagPair>;
	using HandleDivMap = std::map <std::uint64_t, std::tuple<std::vector<int>, std::shared_ptr<int>, bool>>;
	using ScreenMap = std::map<ScreenID, HandleFlagPair>;
	using ModelMap = std::map<std::uint64_t, std::tuple<std::shared_ptr<int>, bool>>;

public:
	ResourceManager();
	~ResourceManager();


	
};

