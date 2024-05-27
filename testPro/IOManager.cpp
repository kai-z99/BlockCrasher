#include "IOManager.h"
#include <iostream>
#include <fstream>
#include "MenuHandler.h"
#include "LevelButton.h"
#include "WindowsFunctions.h"

IOManager::IOManager()
{
    this->levelProgressFileName  = GetAppDataPath() + "/BlockCrasher/levelProgress.txt";
    std::cout << this->levelProgressFileName;
}


void IOManager::SaveLevelProgress(MenuHandler* menuHandler)
{
	std::ofstream levelFile(this->levelProgressFileName);

    if (levelFile.is_open())
    {
        std::vector<LevelButton*>& levelButtons = menuHandler->GetLevelButtons();
        int level = 0;

        for (LevelButton* b : levelButtons)
        {
            levelFile << level << ":";

            if (b->starCoinCollected)
            {
                levelFile << "2";
            }

            else if (b->completed)
            {
                levelFile << "1";
            }

            else
            {
                levelFile << "0";
            }

            levelFile << "\n";
            level++;
        }

        levelFile.close();
    }

    else
    {
        std::cout << "Could not open level file for Save.";
    }
}

void IOManager::LoadLevelProgress(MenuHandler* menuHandler)
{
    std::ifstream levelFile(this->levelProgressFileName);
    

    if (levelFile.is_open())
    {
        std::string line;
        std::vector<LevelButton*>& levelButtons = menuHandler->GetLevelButtons();
        int level = 0;

        while (std::getline(levelFile, line))
        {
            char lastChar = line[line.size() - 1]; // this is the progress number

            if (lastChar == '0')
            {
                levelButtons[level]->completed = false;
                levelButtons[level]->starCoinCollected = false;
            }

            else if (lastChar == '1') // line[]   '0' == 48 != 0
            {
                levelButtons[level]->completed = true;
            }

            else if (lastChar == '2')
            {
                levelButtons[level]->completed = true;
                levelButtons[level]->starCoinCollected = true;
            }

            level++;


        }
        levelFile.close();
    }

    else
    {
        std::cout << "Could not open level file for Load.";
    }

}

void IOManager::ResetLevelProgress(MenuHandler* menuHandler)
{
    std::ofstream levelFile(this->levelProgressFileName);

    if (levelFile.is_open())
    {
        std::vector<LevelButton*> levelButtons = menuHandler->GetLevelButtons();
        int level = 0;

        for (LevelButton* b : levelButtons)
        {
            levelFile << level << ":" << "0\n";
            level++;
        }

        levelFile.close();
    }

    else
    {
        std::cout << "Could not open level file for Reset.\n";
    }

    this->LoadLevelProgress(menuHandler);
}
