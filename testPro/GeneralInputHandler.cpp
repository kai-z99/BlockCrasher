#include "GeneralInputHandler.h"
#include "LevelHandler.h"
#include "Player.h"
#include "LevelStates.h"
#include "MenuHandler.h"
#include "SoundManager.h"
#include "SoundEffect.h"

//check if space is pressed on try again screen, if so reset level
void GeneralInputHandler::HandleTryAgain(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
{
	if (IsKeyPressed(KEY_SPACE) && levelHandler->GetCurrentLevelState() == Fail)
	{
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());
	}
}


//check if space is pressed on level complete screen, if so go to next level
void GeneralInputHandler::HandleLevelComplete(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player, SoundManager* soundManager)
{
	if (IsKeyPressed(KEY_SPACE) && levelHandler->GetCurrentLevelState() == Complete)
	{
		levelHandler->SetLevel(levelHandler->GetCurrentLevel() + 1);
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());

		levelHandler->SetLevelState(Active);
		menuHandler->SetMenuState(InGame);

		//go to next level in menu
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() + 1);

		//have to check if the level increment caused it to go to next page
		if (menuHandler->GetSelectedLevel() % menuHandler->levelsPerPage == 0)
		{
			menuHandler->SetCurrentPage(menuHandler->GetCurrentPage() + 1);
		}

		soundManager->PlaySoundFile(PlayLevel_Sound);
		soundManager->PlayMusic(levelHandler->GetCurrentTrackID());
	}
}


void GeneralInputHandler::HandleBack(Player* player, MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, SoundManager* soundManager)
{
	if (IsKeyPressed(KEY_BACKSPACE))
	{
		switch (menuHandler->GetCurrentState())
		{
		case Main:
			break;

		case LevelSelect:
			menuHandler->SetMenuState(Main);
			soundManager->PlayMusic(0); // 0: main menu track
			break;

		case InGame:
			levelHandler->UnloadCurrentLevel(activeObstacles, activeItems);
			levelHandler->SetLevelState(Inactive);
			menuHandler->SetMenuState(LevelSelect);
			player->SetCurrentColor(player->selectedColorIndex);
			soundManager->PlayMusic(0); 
			break;

		case ChooseColor:
			//if the player pressed backspace, set the players color to what it was originally when they entered the menu. (enter would not make this change as it confirms the color)
			player->SetCurrentColor(menuHandler->initialColorIndex);
			player->SetSelectedColorIndex(menuHandler->initialColorIndex);
			menuHandler->SetMenuState(LevelSelect);
			break;

		default:
			break;
		}

		soundManager->PlaySoundFile(Transition_Sound);
	}
}

void GeneralInputHandler::HandleCurrentMenu(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player, SoundManager* soundManager)
{
	switch (menuHandler->GetCurrentState())
	{
	case Main:
		this->HandleMainMenu(menuHandler, soundManager);
		break;

	case LevelSelect:
		this->HandleSelectLevelMenu(menuHandler, levelHandler, activeObstacles, activeItems, player, soundManager);
		break;

	case ChooseColor:
		this->HandleChooseColorMenu(player, soundManager, menuHandler);
		break;

	default:
		break;
	}
}


void GeneralInputHandler::HandleSelectLevelMenu(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player, SoundManager* soundManager)
{
	//check is level is selected
	if (levelHandler->GetCurrentLevelState() == Inactive && (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)))
	{
		//Initiate the level
		levelHandler->SetLevel(menuHandler->GetSelectedLevel());
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());

		levelHandler->SetLevelState(Active);
		menuHandler->SetMenuState(InGame);

		//play level sound effect
		soundManager->PlaySoundFile(PlayLevel_Sound);

		//play the level's theme
		soundManager->PlayMusic(levelHandler->GetCurrentTrackID());
	}

	//check scroll down
	else if ((levelHandler->GetCurrentLevelState() == Inactive) && ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))) && ((menuHandler->GetSelectedLevel() % menuHandler->levelsPerPage) != 6)) // cannot go further than 6th level of each page 
	{
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() + 1);
		soundManager->PlaySoundFile(Scroll_Sound);
	}

	//check scroll up
	else if (levelHandler->GetCurrentLevelState() == Inactive && (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (menuHandler->GetSelectedLevel() % menuHandler->levelsPerPage != 0)) // cannot go further than firsr level of each page
	{
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() - 1);
		soundManager->PlaySoundFile(Scroll_Sound);
	}

	//check menu right
	else if (levelHandler->GetCurrentLevelState() == Inactive && (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && (menuHandler->GetCurrentPage() != menuHandler->GetPageAmount())) //cant be on last page
	{
		menuHandler->SetCurrentPage(menuHandler->GetCurrentPage() + 1);
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() + menuHandler->levelsPerPage); // set selected level next pages corresponding level
		soundManager->PlaySoundFile(Scroll_Sound);
	}

	//check menu left
	else if (levelHandler->GetCurrentLevelState() == Inactive && (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && (menuHandler->GetCurrentPage() != 1) && (menuHandler->GetCurrentPage() != 1)) // cant be on first page
	{
		menuHandler->SetCurrentPage(menuHandler->GetCurrentPage() - 1);
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() - menuHandler->levelsPerPage); // set selected level next pages corresponding level
		soundManager->PlaySoundFile(Scroll_Sound);
	}

	//check if switch to ChooseColor menu

	else if (levelHandler->GetCurrentLevelState() == Inactive && (IsKeyPressed(KEY_C)))
	{
		menuHandler->initialColorIndex = player->selectedColorIndex; // Store the initial color the player is in initialColorIndex.
		menuHandler->SetMenuState(ChooseColor);
		soundManager->PlaySoundFile(Transition_Sound);
	}


}

void GeneralInputHandler::HandleMainMenu(MenuHandler* menuHandler, SoundManager* soundManager)
{
	//go to level select menu
	if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
	{
		menuHandler->SetMenuState(LevelSelect);
		soundManager->PlayMusic(1); // 1: level select music
		soundManager->PlaySoundFile(Transition_Sound);
	}
}

void GeneralInputHandler::HandleChooseColorMenu(Player* p, SoundManager* soundManager, MenuHandler* menuHandler)
{
	//check right
	if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) /* && ()*/)
	{

		if (p->selectedColorIndex == p->GetColorCount() - 1)
		{
			p->SetSelectedColorIndex(2); // BLUE. Red(0) and Orange(1) are innaccesable.
		}

		else
		{
			p->SetSelectedColorIndex(p->selectedColorIndex + 1);
		}

		p->SetCurrentColor(p->selectedColorIndex);
		soundManager->PlaySoundFile(Scroll_Sound);
	}

	//check left
	else if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) /* && ()*/)
	{
		if (p->selectedColorIndex == 2) // BLUE. Red(0) and Orange(1) are innaccesable.
		{
			p->SetSelectedColorIndex(p->GetColorCount() - 1);
		}

		else
		{
			p->SetSelectedColorIndex(p->selectedColorIndex - 1);
		}
		
		p->SetCurrentColor(p->selectedColorIndex);
		soundManager->PlaySoundFile(Scroll_Sound);
	}

	else if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
	{
		// See HandleBack to revert color to prevoius state.
		menuHandler->SetMenuState(LevelSelect);
		soundManager->PlaySoundFile(Transition_Sound);
	}

}
