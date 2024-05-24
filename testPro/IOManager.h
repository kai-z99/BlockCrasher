#pragma once
#include <string>

class MenuHandler;

class IOManager
{
private:
	std::string levelProgressFileName;
	
public:
	IOManager();
	void SaveLevelProgress(MenuHandler* menuHandler);
	void LoadLevelProgress(MenuHandler* menuHandler);
	void ResetLevelProgress(MenuHandler* menuHandler);
};