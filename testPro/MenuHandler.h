#pragma once
#include "raylib.h"
#include <vector>
#include "MenuState.h"

class LevelButton;
class LevelHandler;
class Player;

class MenuHandler
{
private:

	//----------
	//GENERAL
	//----------
	MenuState currentState;

	void DrawBackButton();
	const char* backButtonText;
	int backButtonTextWidth;
	
	//----------
	//LEVEL SELECT
	//----------
	std::vector<LevelButton*> levelButtons;
	std::vector<const char*> levelNames;
	int currentSelectedLevel;
	int currentPage;
	
	int levelButtonHeight;
	int levelButtonWidth;

	void InitLevelSelectMenuButtons();
	void DrawLevelSelectMenu(unsigned int frame);

	void DrawLevelButtons(int page);
	void DrawSelectedLevelIndicator(unsigned int frame);
	void DrawLevelSelectTitle();
	void DrawPageArrows(unsigned int frame);
	void DrawLevelSelectInstruction();
	void DrawDifficulty(int type); // type 0: for levelSelect, type 1: for InGame


	const char* levelSelectTitleText;
	int levelSelectTitleWidth;
	
	const char* levelSelectInstructionText1;
	const char* levelSelectDifficultyText;
	

	//----------
	//MAIN
	//---------
	const char* mainMenuTitleText;
	int mainMenuTitleTextWidth;

	const char* mainMenuSubtext;
	int mainMenuSubtextWidth;

	const char* creditsText;
	int creditsTextWidth;

	void DrawMainMenu();

	void DrawMainMenuTitle();
	void DrawMainMenuSubtext();

	//----------
	//INGAME
	//---------
	void DrawInGameTimer(LevelHandler* levelHandler);
	void DrawLevelName();

	//----------
	//CHOOSE COLOR
	//---------

	void DrawChooseColorMenu(Player* p);
	void DrawChooseColorBox();
	void DrawChooseColorText(); // arrows to change colors
	void DrawChooseColorText2(); // enter / space to confirm
	void DrawPlayerChooseColor(Player* p);
	void DrawChooseColorArrows();
	

	const char* chooseColorText;
	int chooseColorTextWidth;

	const char* chooseColorText2;
	int chooseColorTextWidth2;

	


public:
	MenuHandler();
	MenuState GetCurrentState() const;
	void SetMenuState(MenuState state);
	void DrawCurrentMenu(LevelHandler* levelHandler, Player* player, unsigned int frame);
	std::vector<LevelButton*>& GetLevelButtons();

	//----------
	//LEVEL SELECT
	//----------
	const int levelsPerPage = 7;

	void SetSelectedLevel(int level);
	void SetLevelComplete(int level);
	void SetLevelStarCoinCollected(int level);
	void SetCurrentPage(int page);

	int GetSelectedLevel() const;
	int GetCurrentPage() const;
	int GetPageAmount() const;

	//----------
	//CHOOSE COLOR
	//----------

	int initialColorIndex; // the intial color the player is when you enter the menu
};