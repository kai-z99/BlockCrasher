#pragma once
#include "raylib.h"
#include <vector>

class LevelButton;

class MenuHandler
{
private:
	std::vector<LevelButton*> levelButtons;
	int currentSelectedLevel;

	int levelButtonHeight;
	int levelButtonWidth;

	void InitLevelSelectPage1();

	void DrawLevelButtons();
	void DrawSelectedLevelIndicator();
	void DrawLevelSelectTitle();

	int levelSelectTitleWidth;
	const char* levelSelectTitleText;
	

public:
	MenuHandler();

	void DrawLevelSelectMenu();
	void SetSelectedLevel(int level);
	void SetLevelComplete(int level);
	void SetLevelStarCoinCollected(int level);

	int GetSelectedLevel() const;
	int GetLevelsOnPage() const;

};