#pragma once
#include "raylib.h"
#include <vector>

class LevelButton;

class MenuHandler
{
private:
	std::vector<LevelButton*> levelButtons;
	int currentSelectedLevel;
	int currentPage;
	

	int levelButtonHeight;
	int levelButtonWidth;

	void InitLevelSelectMenuButtons();

	void DrawLevelButtons(int page);
	void DrawSelectedLevelIndicator();
	void DrawLevelSelectTitle();
	void DrawPageArrows();

	int levelSelectTitleWidth;
	const char* levelSelectTitleText;
	

public:
	MenuHandler();

	const int levelsPerPage = 7;

	void DrawLevelSelectMenu();
	void SetSelectedLevel(int level);
	void SetLevelComplete(int level);
	void SetLevelStarCoinCollected(int level);
	void SetCurrentPage(int page);

	int GetSelectedLevel() const;
	//int GetLevelsOnPage() const;
	int GetCurrentPage() const;
	int GetPageAmount() const;

};