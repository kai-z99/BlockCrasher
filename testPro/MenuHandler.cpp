#include "MenuHandler.h"
#include "LevelButton.h"
#include "LevelHandler.h"
#include "Constants.h"
#include <string>





MenuHandler::MenuHandler()
{
	this->currentState = Main;

	//----------
	//LEVEL SELECT
	//----------
	this->currentSelectedLevel = 0;
	this->currentPage = 1;
	this->levelButtonHeight = 60;
	this->levelButtonWidth = 600;
	this->levelSelectTitleText = "Select a Level!";
	this->levelSelectTitleWidth = MeasureText(this->levelSelectTitleText, 75);
	this->InitLevelSelectMenuButtons(); 


	//----------
	//MAIN
	//----------
	this->mainMenuTitleText = "MenuText";
	this->mainMenuTitleTextWidth = MeasureText(this->mainMenuTitleText, 80);
	this->mainMenuSubtext = "Press Space/Enter to start!";
	this->mainMenuSubtextWidth = MeasureText(this->mainMenuSubtext, 18);

}

MenuState MenuHandler::GetCurrentState() const
{
	return this->currentState;
}

void MenuHandler::SetMenuState(MenuState state)
{
	this->currentState = state;
}

//----------
//LEVEL SELECT
//----------

void MenuHandler::InitLevelSelectMenuButtons()
{
	//make this a for loop maybe
	int posX = (screenWidth / 2) - (this->levelButtonWidth / 2); // middle of screen
	std::vector<const char*> levelNames =
	{
		"0: Tutorial",
		"1: Sword Swing",
		"2: WIP WIP WIP",
		"3: Bounce Dungeon",
		"4: Cubed",
		"5: Violent Tides",
		"6: High Pressure",

		"7: placeholderp2",
		"8: ph2",
		"9: 555",
		"10: test tsewt",
		"11: r4323e2ref",
		"12: rwerrew",
		"13: gogogoog",

		"14: thrid",
		"15: yap",
		"16: hhhhh",
		"17: 3241312132",
		"18: cmoiw",
		"19: 21",
		"20: 211121212"

		//"Created by Kai @ Van"
	};


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


void MenuHandler::DrawLevelSelectMenu()
{
	this->DrawLevelButtons(this->currentPage);
	this->DrawSelectedLevelIndicator();
	this->DrawLevelSelectTitle();
	this->DrawPageArrows();
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

void MenuHandler::DrawSelectedLevelIndicator()
{
	//DrawCircleLines(600, (this->levelButtons[currentSelectedLevel]->GetPosY()) + ((float)this->levelButtonHeight / 2), 10, WHITE);

	DrawTriangleLines(
		{ 600, (this->levelButtons[currentSelectedLevel]->GetPosY()) + ((float)this->levelButtonHeight / 2) }, 
		{ 570, (this->levelButtons[currentSelectedLevel]->GetPosY()) + ((float)this->levelButtonHeight / 2) - 20},
		{ 570, (this->levelButtons[currentSelectedLevel]->GetPosY()) + ((float)this->levelButtonHeight / 2) + 20 },
		WHITE
	
	);
}


void MenuHandler::DrawLevelSelectTitle()
{
	DrawText(this->levelSelectTitleText, (screenWidth / 2) - this->levelSelectTitleWidth / 2, 100, 75, WHITE);
}

void MenuHandler::DrawPageArrows()
{
	if (this->GetCurrentPage() != this->GetPageAmount()) // right arrow
	{
		DrawTriangleLines(
			{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 200, (screenHeight / 2) + 30},
			{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 180, (screenHeight / 2)  + 5 },
			{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 180, (screenHeight / 2) + 55 },
			WHITE
		);
	}

	if (this->GetCurrentPage() != 1) // left arrow
	{
		DrawTriangleLines(
			{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 200, (screenHeight / 2) + 30 },
			{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 180, (screenHeight / 2) + 5 },
			{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 180, (screenHeight / 2) + 55 },
			WHITE
		);
	}
}


void MenuHandler::DrawCurrentMenu(LevelHandler* levelHandler)
{
	switch (this->currentState)
	{
	case Main:
		this->DrawMainMenu();
		break;

	case LevelSelect:
		this->DrawLevelSelectMenu();
		break;

	case InGame:
		this->DrawInGameTimer(levelHandler);
		break;

	}

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
	return ((this->levelButtons.size() - 1) / this->levelsPerPage) + 1; // check this
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

	DrawText(timer.c_str(), (screenWidth / 2) - (timerWidth / 2), 30, 30, col );
	//DrawText("Active", 50, 50, 50, RED); //debug
}