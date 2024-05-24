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
	void DrawLevelSelectMenu();

	void DrawLevelButtons(int page);
	void DrawSelectedLevelIndicator();
	void DrawLevelSelectTitle();
	void DrawPageArrows();
	void DrawLevelSelectInstruction();


	const char* levelSelectTitleText;
	int levelSelectTitleWidth;
	
	const char* levelSelectInstructionText1;
	

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
	void DrawCurrentMenu(LevelHandler* levelHandler, Player* player);
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