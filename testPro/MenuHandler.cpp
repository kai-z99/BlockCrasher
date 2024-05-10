#include "MenuHandler.h"
#include "LevelButton.h"
#include "Constants.h"


MenuHandler::MenuHandler()
{
	this->currentSelectedLevel = 0;
	this->currentPage = 1;
	this->levelButtonHeight = 60;
	this->levelButtonWidth = 600;
	this->levelSelectTitleText = "Select a Level!";
	this->levelSelectTitleWidth = MeasureText(this->levelSelectTitleText, 75);
	

	this->InitLevelSelectMenuButtons(); 
}

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
		"6: PlaceHolder 4",
		"7: placeholderp2",
		"8: ph2",
		"9: 555",
		"10: test tsewt",
		"11: r4323e2ref",
		"12: rwerrew",
		"13: gogogoog"

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
}//																																start at level 7


void MenuHandler::DrawLevelSelectMenu()
{
	this->DrawLevelButtons(this->currentPage);
	this->DrawSelectedLevelIndicator();
	this->DrawLevelSelectTitle();
	this->DrawPageArrows();
}

void MenuHandler::DrawLevelButtons(int page)
{
	switch (page)
	{
	case 1: // draw first 6 levels (page 1)
		for (int i = 0; i <= 6; i++)
		{
			this->levelButtons[i]->Draw();
		}

		break;

	case 2: // 7 to 11 (page 2)
		for (int i = 7; i <= 13; i++)
		{
			this->levelButtons[i]->Draw();
		}

		break;

	default: //draw page 1 (debug)
		for (int i = 0; i <= 6; i++)
		{
			this->levelButtons[i]->Draw();
		}

		break;

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
	if (this->GetCurrentPage() != this->GetPageAmount())
	{
		DrawTriangleLines(
			{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 200, (screenHeight / 2) + 30},
			{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 180, (screenHeight / 2)  + 5 },
			{ ((float)screenWidth / 2) + (this->levelButtonWidth / 2) + 180, (screenHeight / 2) + 55 },
			WHITE

		);
	}

	if (this->GetCurrentPage() != 1)
	{
		DrawTriangleLines(
			{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 200, (screenHeight / 2) + 30 },
			{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 180, (screenHeight / 2) + 5 },
			{ ((float)screenWidth / 2) - (this->levelButtonWidth / 2) - 180, (screenHeight / 2) + 55 },
			WHITE

		);
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

//int MenuHandler::GetLevelsOnPage() const
//{
//	return 7;
//}

int MenuHandler::GetCurrentPage() const
{
	return this->currentPage;
}

int MenuHandler::GetPageAmount() const
{
	return ((this->levelButtons.size() - 1) / this->levelsPerPage) + 1;
}


//void MenuHandler::AddLevelButton(float x, float y, float w, float h, const char* text, Color color)
//{
//	this->levelButtons.push_back(new LevelButton(x,y,w,h,text,color));
//}
