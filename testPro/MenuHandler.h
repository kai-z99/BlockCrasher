#pragma once
#include "raylib.h"
#include <vector>
#include "MenuState.h"

class LevelButton;
class LevelHandler;

class MenuHandler
{
private:
	MenuState currentState;

	//----------
	//LEVEL SELECT
	//----------
	std::vector<LevelButton*> levelButtons;
	int currentSelectedLevel;
	int currentPage;
	

	int levelButtonHeight;
	int levelButtonWidth;

	void InitLevelSelectMenuButtons();
	void DrawLevelSelectMenu();

	void DrawLevelButtons(int page);
	void DrawSelectedLevelIndicator();
	void DrawLevelSelectTitle();
	void DrawPageArrows();

	int levelSelectTitleWidth;
	const char* levelSelectTitleText;

	//----------
	//MAIN
	//---------
	const char* mainMenuTitleText;
	int mainMenuTitleTextWidth;

	const char* mainMenuSubtext;
	int mainMenuSubtextWidth;

	void DrawMainMenu();

	void DrawMainMenuTitle();
	void DrawMainMenuSubtext();

	//----------
	//INGAME
	//---------
	void DrawInGameTimer(LevelHandler* levelHandler);


public:
	MenuHandler();
	MenuState GetCurrentState() const;
	void SetMenuState(MenuState state);

	//----------
	//LEVEL SELECT
	//----------
	const int levelsPerPage = 7;

	void DrawCurrentMenu(LevelHandler* levelHandler);

	void SetSelectedLevel(int level);
	void SetLevelComplete(int level);
	void SetLevelStarCoinCollected(int level);
	void SetCurrentPage(int page);

	int GetSelectedLevel() const;
	int GetCurrentPage() const;
	int GetPageAmount() const;
	
	//----------
	//MAIN
	//---------

	


};