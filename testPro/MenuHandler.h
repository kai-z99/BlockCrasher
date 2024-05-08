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

	Vector2 levelSelectTitleDimensions;
	const char* levelSelectTitleText;
	void DrawLevelSelectTitle();

public:
	MenuHandler();
	//void AddLevelButton(float x, float y, float w, float h, const char* text, Color color);
	void DrawLevelSelectMenu();

	void SetSelectedLevel(int level);

	int GetSelectedLevel() const;
	int GetLevelsOnPage() const;
};