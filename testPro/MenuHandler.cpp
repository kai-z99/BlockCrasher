#include "MenuHandler.h"
#include "LevelButton.h"
#include "Constants.h"


MenuHandler::MenuHandler()
{
	this->currentSelectedLevel = 0;
	this->levelButtonHeight = 60;
	this->levelButtonWidth = 600;
	this->levelSelectTitleText = "Select a Level!";
	this->levelSelectTitleWidth = MeasureText(this->levelSelectTitleText, 75);
	

	this->InitLevelSelectPage1(); 
}

void MenuHandler::DrawLevelSelectMenu()
{
	this->DrawLevelButtons();
	this->DrawSelectedLevelIndicator();
	this->DrawLevelSelectTitle();
}

void MenuHandler::InitLevelSelectPage1()
{
	//make this a for loop maybe
	int posX = (screenWidth / 2) - (this->levelButtonWidth / 2); // middle of screen
	std::vector<const char*> levelNames =
	{
		"0: Tutorial",
		"1: Sword Swing",
		"2: PlaceHolder 1",
		"3: Bounce Dungeon",
		"4: PlaceHolder 2",
		"5: PlaceHolder 3",
		"6: PlaceHolder 4",
		//"Created by Kai @ Van"
	};


	for (int i = 0; i < 7; i++)
	{
		this->levelButtons.push_back(new LevelButton(posX, 200 + (100 * (i + 1)), this->levelButtonWidth, this->levelButtonHeight, levelNames[i], 0, WHITE)); // remove level  param most liekl,y
	}		//										  ^
	//                                          middle of screen    
	//																^
	//														start at y = 200, increment 100 every button
}


void MenuHandler::DrawLevelButtons()
{
	for (LevelButton* lb : this->levelButtons)
	{
		lb->Draw();
	}
}

void MenuHandler::DrawSelectedLevelIndicator()
{
	DrawCircleLines(600, (this->levelButtons[currentSelectedLevel]->GetPosY()) + ((float)this->levelButtonHeight / 2), 10, WHITE);
}


void MenuHandler::DrawLevelSelectTitle()
{
	DrawText(this->levelSelectTitleText, (screenWidth / 2) - this->levelSelectTitleWidth / 2, 100, 75, WHITE);
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

int MenuHandler::GetSelectedLevel() const
{
	return this->currentSelectedLevel;
}

int MenuHandler::GetLevelsOnPage() const
{
	return this->levelButtons.size();
}


//void MenuHandler::AddLevelButton(float x, float y, float w, float h, const char* text, Color color)
//{
//	this->levelButtons.push_back(new LevelButton(x,y,w,h,text,color));
//}
