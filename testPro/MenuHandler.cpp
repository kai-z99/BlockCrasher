#include "MenuHandler.h"
#include "LevelButton.h"
#include "LevelHandler.h"
#include "Player.h"
#include "Constants.h"
#include <string>



MenuHandler::MenuHandler()
{
	//----------
	//GENERAL
	//----------

	this->currentState = Main;
	this->backButtonText = "BACKSPACE to exit.";
	this->backButtonTextWidth = MeasureText(this->backButtonText, 20);

	//----------
	//LEVEL SELECT
	//----------

	this->currentSelectedLevel = 0;
	this->currentPage = 1;
	this->levelButtonHeight = 60;
	this->levelButtonWidth = 600;
	this->levelSelectTitleText = "Select a Level!";
	this->levelSelectTitleWidth = MeasureText(this->levelSelectTitleText, 75);
	this->levelSelectInstructionText1 = "Choose a level with WASD / ARROW KEYS.\n\n     Press SPACE / ENTER to play!\n\n    Press 'C' to change player color!";
	this->levelSelectDifficultyText = "Difficulty:";
	
	this->levelNames =
	{
		"0: Tutorial",
		"1: Sword Swing",
		"2: Big and Small",
		"3: Bounce Dungeon",
		"4: Cubed",
		"5: Violent Tides",
		"6: High Pressure",

		"7: Gridlock",
		"8: Happy Tree Carol",
		"9: Deep Terrors",
		"10: The Vortex",
		"11: IronSteel Factory",
		"12: Heavy Blizzard",
		"13: Dreadnaught Seas",

		"14: COMING SOON",
		"15: COMING SOON",
		"16: COMING SOON",
		"17: COMING SOON",
		"18: COMING SOON",
		"19: COMING SOON",
		"20: COMING SOON"

		//"Created by Kai @ Van"

		
	};

	this->InitLevelSelectMenuButtons();

	//----------
	//MAIN
	//----------

	this->mainMenuTitleText = "Welcome to: Block Crasher";
	this->mainMenuTitleTextWidth = MeasureText(this->mainMenuTitleText, 80);
	this->mainMenuSubtext = "Press Space/Enter to start!";
	this->mainMenuSubtextWidth = MeasureText(this->mainMenuSubtext, 18);
	this->creditsText = "Developed By: Kai Z";
	this->creditsTextWidth = MeasureText(this->creditsText, 30);


	//----------
	//CHOOSE COLOR
	//----------

	this->chooseColorText = "Switch color with WASD / ARROW KEYS!";
	this->chooseColorTextWidth = MeasureText(this->chooseColorText, 30);
	this->chooseColorText2 = "Press ENTER / SPACE to confirm!";
	this->chooseColorTextWidth2 = MeasureText(this->chooseColorText2, 30);

	this->initialColorIndex = 2; // the game starts as blue as the player color.

}

MenuState MenuHandler::GetCurrentState() const
{
	return this->currentState;
}

void MenuHandler::SetMenuState(MenuState state)
{
	this->currentState = state;
}

void MenuHandler::DrawBackButton()
{
	DrawText(this->backButtonText, screenWidth - this->backButtonTextWidth - 20, 20, 20, WHITE);
}


//----------
//LEVEL SELECT
//----------


void MenuHandler::InitLevelSelectMenuButtons()
{
	//make this a for loop maybe
	int posX = (screenWidth / 2) - (this->levelButtonWidth / 2); // middle of screen


	for (int i = 0; i <= 6; i++)
	{
		this->levelButtons.push_back(new LevelButton(posX, 200 + (100 * (i + 1)), this->levelButtonWidth, this->levelButtonHeight, levelNames[i], WHITE)); 
	}		//										  ^
	//                                          middle of screen    
	//																^
	//														start at y = 200, increment 100 every button


	for (int i = 0; i <= 6; i++) // page 2. reset positions, but start at level 7.
	{
		this->levelButtons.push_back(new LevelButton(posX, 200 + (100 * (i + 1)), this->levelButtonWidth, this->levelButtonHeight, levelNames[7 + i], WHITE));
	}	
																														//              ^
																														//		start at level 7

	for (int i = 0; i <= 6; i++) //page 3
	{
		this->levelButtons.push_back(new LevelButton(posX, 200 + (100 * (i + 1)), this->levelButtonWidth, this->levelButtonHeight, levelNames[14 + i], WHITE));
	}

}																														

void MenuHandler::DrawLevelSelectMenu(unsigned int frame)
{
	this->DrawLevelButtons(this->currentPage);
	this->DrawSelectedLevelIndicator(frame);
	this->DrawLevelSelectTitle();
	this->DrawPageArrows(frame);
	this->DrawLevelSelectInstruction();
	this->DrawDifficulty(0);
}

void MenuHandler::DrawLevelButtons(int page)
{
	//if (page == this->GetPageAmount()) // TEMP ELSE STATEMENT (USE WHEN ALL MENUS NOT FILLED TO PREVNT CRASHES)
	//{
	//	for (int i = 0 + ((page - 1) * this->levelsPerPage); i <= 15; i++)
	//	{
	//		this->levelButtons[i]->Draw();
	//	}
	//}

	//                     0, 7, 14, ....                             // 6, 13, 20, ...
	for (int i = 0 + ((page - 1) * this->levelsPerPage); i <= (6 + ((page - 1) * this->levelsPerPage)); i++)
	{
		this->levelButtons[i]->Draw();
	}	
}

void MenuHandler::DrawSelectedLevelIndicator(unsigned int frame)
{
	//flashing white

	Color col = { 255,255,255,(unsigned char)(255 * abs(sin(frame * 0.1)))};

	DrawTriangle(
		//THIS IS CLOCKWISE (on standard axis)
		{ 600, (this->levelButtons[currentSelectedLevel]->GetPosY()) + ((float)this->levelButtonHeight / 2) }, 
		{ 570, (this->levelButtons[currentSelectedLevel]->GetPosY()) + ((float)this->levelButtonHeight / 2) - 20},
		{ 570, (this->levelButtons[currentSelectedLevel]->GetPosY()) + ((float)this->levelButtonHeight / 2) + 20 },
		col
	
	);
}


void MenuHandler::DrawLevelSelectTitle()
{
	DrawText(this->levelSelectTitleText, (screenWidth / 2) - this->levelSelectTitleWidth / 2, 100, 75, WHITE);
}

void MenuHandler::DrawPageArrows(unsigned int frame)
{
	//flashing white
	Color col = { 255,255,255,(unsigned char)(255 * abs(cos(frame * 0.05)))};
	

	if (this->GetCurrentPage() != this->GetPageAmount()) // right arrow
	{
		//inner flashing
		DrawTriangle(
			{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 180, (screenHeight / 2) + 30},
			{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 160, (screenHeight / 2)  + 5 },
			{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 160, (screenHeight / 2) + 55 },
			col
		);

		//white outline
		//DrawTriangleLines(
		//	{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 180, (screenHeight / 2) + 30 },
		//	{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 160, (screenHeight / 2) + 5 },
		//	{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 160, (screenHeight / 2) + 55 },
		//	WHITE
		//);
	}

	if (this->GetCurrentPage() != 1) // left arrow
	{
		//inner flashing //THIS IS COUNTERCLOCKWISE (on standard axis)
		DrawTriangle(
			{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 160, (screenHeight / 2) + 5 },
			{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 180, (screenHeight / 2) + 30 },
			{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 160, (screenHeight / 2) + 55 },
			col
		);

		//white outline
		//DrawTriangleLines(
		//	{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 180, (screenHeight / 2) + 30 },
		//	{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 160, (screenHeight / 2) + 5 },
		//	{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 160, (screenHeight / 2) + 55 },
		//	WHITE
		//);
		
	}
}

void MenuHandler::DrawLevelSelectInstruction()
{
	DrawText(this->levelSelectInstructionText1, 20, screenHeight / 2, 20, WHITE);
}

void MenuHandler::DrawDifficulty(int type)
{
	// if its in levelSelect menu, write "Difficulty:"
	if (type == 0)
	{
		DrawText(this->levelSelectDifficultyText, screenWidth - 300, screenHeight / 2, 20, WHITE);
	}
	
	std::string difficulty;
	Color col;

	if (this->currentSelectedLevel >= 12 && this->currentSelectedLevel < 14)
	{
		difficulty = "Cruel";
		col = { 105, 4, 4 , 255};
	}

	else if (this->currentSelectedLevel >= 10 && this->currentSelectedLevel < 12)
	{
		difficulty = "Extreme";
		col = RED;
	}

	else if (this->currentSelectedLevel >= 7 && this->currentSelectedLevel < 10)
	{
		difficulty = "Insane";
		col = { 252, 82, 3, 255 };
	}

	else if (this->currentSelectedLevel >= 5 && this->currentSelectedLevel < 7)
	{
		difficulty = "Very Hard";
		col = ORANGE;
	}

	else if (this->currentSelectedLevel >= 3 && this->currentSelectedLevel < 5)
	{
		difficulty = "Challenging";
		col = YELLOW;
	}

	else if (this->currentSelectedLevel >= 1 && this->currentSelectedLevel < 3)
	{
		difficulty = "Mild";
		col = GREEN;
	}

	else
	{
		difficulty = "N/A";
		col = GRAY;
	}

	

	if (type == 0)
	{
		int textWidth = MeasureText(difficulty.c_str(), 40);
		DrawText(difficulty.c_str(), (screenWidth - 250) - (textWidth / 2), screenHeight / 2 + 40, 40, col);
	}

	else
	{
		DrawText(difficulty.c_str(), 30, 60, 20, col);
	}
}


//----------
//MAIN
//----------
void MenuHandler::DrawMainMenu()
{
	this->DrawMainMenuTitle();
	this->DrawMainMenuSubtext();
}

void MenuHandler::DrawMainMenuTitle()
{
	DrawText(this->mainMenuTitleText, (screenWidth / 2) - (this->mainMenuTitleTextWidth / 2), screenHeight / 2, 80, WHITE);
}

void MenuHandler::DrawMainMenuSubtext()
{
	DrawText(this->mainMenuSubtext, (screenWidth / 2) - (this->mainMenuSubtextWidth / 2), (screenHeight / 2) + 80, 18, WHITE);
	DrawText(this->creditsText, screenWidth - this->creditsTextWidth - 10, screenHeight - 35, 30, WHITE);
}

//----------
//INGAME
//----------

void MenuHandler::DrawInGameTimer(LevelHandler* levelHandler)
{
	std::string timer = std::to_string(levelHandler->GetCurrentLevelTime());
	int timerWidth = MeasureText(timer.c_str(), 30);
	Color col;

	//make timer red if its down to the last 25% + 1s of remaining time
	if (levelHandler->GetCurrentLevelTime() < (levelHandler->GetCurrentLevelTimeLimit() / 4) + 1)
	{
		col = RED;
	}

	else
	{
		col = WHITE;
	}

	DrawText(timer.c_str(), (screenWidth / 2) - (timerWidth / 2), 30, 30, col);
	//DrawText("Active", 50, 50, 50, RED); //debug
}

void MenuHandler::DrawLevelName()
{
	DrawText(this->levelNames[this->currentSelectedLevel], 30, 30, 30, WHITE);
}

//------------
//CHOOSE COLOR
//------------

void MenuHandler::DrawChooseColorMenu(Player* p)
{
	this->DrawChooseColorBox();
	this->DrawChooseColorText();
	this->DrawChooseColorText2();
	this->DrawPlayerChooseColor(p);
	this->DrawChooseColorArrows();
}

void MenuHandler::DrawChooseColorBox()
{
	DrawRectangleLines(screenWidth / 2 - 50, screenHeight / 2 - 50, 100, 100, WHITE);
}

void MenuHandler::DrawChooseColorText()
{
	DrawText(this->chooseColorText, (screenWidth / 2) - (this->chooseColorTextWidth / 2), screenHeight / 2 - 200, 30, WHITE);
}

void MenuHandler::DrawChooseColorText2()
{
	DrawText(this->chooseColorText2, (screenWidth / 2) - (this->chooseColorTextWidth2 / 2), screenHeight / 2 + 200, 30, WHITE);
}

void MenuHandler::DrawPlayerChooseColor(Player* p)
{
	p->SetPosition({ screenWidth / 2, screenHeight / 2 });
	p->SetDirection(N);
	p->Draw();
}

void MenuHandler::DrawChooseColorArrows()
{
	DrawTriangleLines
	(
		{ ((float)screenWidth / 2) + 200, (screenHeight / 2) + 0 },
		{ ((float)screenWidth / 2) + 180, (screenHeight / 2) - 25 },
		{ ((float)screenWidth / 2) + 180, (screenHeight / 2) + 25 },
		WHITE
	);

	DrawTriangleLines
	(
		{ ((float)screenWidth / 2) - 200, (screenHeight / 2) + 0 },
		{ ((float)screenWidth / 2) - 180, (screenHeight / 2) - 25 },
		{ ((float)screenWidth / 2) - 180, (screenHeight / 2) + 25 },
		WHITE
	);

}

//draw menu func

void MenuHandler::DrawCurrentMenu(LevelHandler* levelHandler, Player* player, unsigned int frame)
{
	switch (this->currentState)
	{
	case Main:
		this->DrawMainMenu();
		break;

	case LevelSelect:
		this->DrawLevelSelectMenu(frame);
		break;

	case InGame:
		this->DrawInGameTimer(levelHandler);
		this->DrawLevelName();
		this->DrawDifficulty(1);
		break;

	case ChooseColor:
		this->DrawChooseColorMenu(player);
		break;

	}

	//draw the go back button
	if (this->currentState != Main)
	{
		this->DrawBackButton();

	}
}

std::vector<LevelButton*>& MenuHandler::GetLevelButtons()
{
	return this->levelButtons;
}

void MenuHandler::SetSelectedLevel(int level)
{
	this->currentSelectedLevel = level;
}

void MenuHandler::SetLevelComplete(int level)
{
	this->levelButtons[level]->completed = true;
}

void MenuHandler::SetLevelStarCoinCollected(int level)
{
	this->levelButtons[level]->starCoinCollected = true;
}

void MenuHandler::SetCurrentPage(int page)
{
	this->currentPage = page;
}

int MenuHandler::GetSelectedLevel() const
{
	return this->currentSelectedLevel;
}

int MenuHandler::GetCurrentPage() const
{
	return this->currentPage;
}

int MenuHandler::GetPageAmount() const
{
	return (((int)this->levelButtons.size() - 1) / this->levelsPerPage) + 1; // check this
}



