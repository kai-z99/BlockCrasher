#include "SoundManager.h"

SoundManager::SoundManager()
{
	InitAudioDevice();

	//------------------------------------------------------
	//MUSIC LOADING
	//------------------------------------------------------

	this->mainMenuMusic = LoadMusicStream("Sounds/MainMenu_Music.mp3"); // 0
	SetMusicVolume(this->mainMenuMusic, 0.3f);
	this->tracks.push_back(&this->mainMenuMusic);

	this->levelSelectMusic = LoadMusicStream("Sounds/LevelSelect_Music.mp3"); // 1
	SetMusicVolume(this->levelSelectMusic, 0.5f);
	this->tracks.push_back(&this->levelSelectMusic);

	this->TutorialMusic = LoadMusicStream("Sounds/Tutorial_Music.mp3"); // 2
	this->tracks.push_back(&this->TutorialMusic);

	this->BigAndSmallMusic = LoadMusicStream("Sounds/BigAndSmall_Music.wav"); // 3
	SetMusicVolume(this->BigAndSmallMusic, 0.4f);
	SetMusicPitch(this->BigAndSmallMusic, 1.2f);
	this->tracks.push_back(&this->BigAndSmallMusic);

	this->BounceDungeonMusic = LoadMusicStream("Sounds/BounceDungeon_Music.wav"); // 4
	this->tracks.push_back(&this->BounceDungeonMusic);

	this->CubedMusic = LoadMusicStream("Sounds/Cubed_Music.mp3"); // 5
	SetMusicVolume(this->CubedMusic, 0.25f);
	SetMusicPitch(this->CubedMusic, 0.88f);
	this->tracks.push_back(&this->CubedMusic);

	this->GridLockMusic = LoadMusicStream("Sounds/GridLock_Music.mp3"); // 6
	this->tracks.push_back(&this->GridLockMusic);
	
	this->DesertedMusic = LoadMusicStream("Sounds/Deserted_Music.wav"); // 7
	SetMusicVolume(this->DesertedMusic, 0.7f);
	SetMusicPitch(this->DesertedMusic, 0.7f);
	this->tracks.push_back(&this->DesertedMusic);

	this->HappyTreeMusic = LoadMusicStream("Sounds/HappyTree_Music2.wav"); // 8
	SetMusicVolume(this->HappyTreeMusic, 0.2f);
	SetMusicPitch(this->HappyTreeMusic, 1.25f);
	this->tracks.push_back(&this->HappyTreeMusic);

	this->HighPressureMusic = LoadMusicStream("Sounds/HighPressure_Music.mp3"); // 9
	SetMusicVolume(this->HighPressureMusic, 0.3f);
	this->tracks.push_back(&this->HighPressureMusic);

	this->ViolentTidesMusic = LoadMusicStream("Sounds/ViolentTides_Music.mp3"); // 10
	SetMusicVolume(this->ViolentTidesMusic, 0.2f);
	this->tracks.push_back(&this->ViolentTidesMusic);

	this->VortexMusic = LoadMusicStream("Sounds/Vortex_Music.mp3"); // 11
	SetMusicVolume(this->VortexMusic, 0.4f);
	this->tracks.push_back(&this->VortexMusic);

	this->SwordSwingMusic = LoadMusicStream("Sounds/SwordSwing_Music.mp3"); // 12
	SetMusicVolume(this->SwordSwingMusic, 0.4f);
	SetMusicPitch(this->SwordSwingMusic, 1.25f);
	this->tracks.push_back(&this->SwordSwingMusic);

	this->IronSteelFactoryMusic = LoadMusicStream("Sounds/Factory_Music.mp3"); // 13
	SetMusicVolume(this->IronSteelFactoryMusic, 0.2f);
	this->tracks.push_back(&this->IronSteelFactoryMusic);

	this->currentMusic = this->mainMenuMusic; // default song is main menu


	//------------------------------------------------------
	//SOUND EFFECT LOADING
	//------------------------------------------------------

	this->CoinCollectSound = LoadSound("Sounds/1LineClear.mp3");
	SetSoundVolume(this->CoinCollectSound, 0.5f);
	this->sounds.push_back(&this->CoinCollectSound);

	this->StarCoinCollectSound = LoadSound("Sounds/3LineClear.mp3");
	SetSoundVolume(this->StarCoinCollectSound, 0.5f);
	this->sounds.push_back(&this->StarCoinCollectSound);

	this->ScrollSound = LoadSound("Sounds/EnemyRotate.mp3");
	this->sounds.push_back(&this->ScrollSound);

	this->PlayLevelSound = LoadSound("Sounds/EnemySpawn.mp3");
	this->sounds.push_back(&this->PlayLevelSound);

	this->LevelWinSound = LoadSound("Sounds/Lose.mp3");
	SetSoundVolume(this->LevelWinSound, 0.5f);
	this->sounds.push_back(&this->LevelWinSound);

	this->LevelLoseSound = LoadSound("Sounds/Detonate.mp3");
	SetSoundVolume(this->LevelLoseSound, 0.3f);
	SetSoundPitch(this->LevelLoseSound, 1.5f);
	this->sounds.push_back(&this->LevelLoseSound);

	this->TransitionSound = LoadSound("Sounds/UndoRotate.mp3");
	SetSoundVolume(this->TransitionSound, 0.75f);
	this->sounds.push_back(&this->TransitionSound);

	this->TimesUpSound = LoadSound("Sounds/Beep.mp3");
	SetSoundVolume(this->TimesUpSound, 1.5f);
	this->sounds.push_back(&this->TimesUpSound);
}

SoundManager::~SoundManager()
{
	CloseAudioDevice();

	for (Music* m : this->tracks) // unload music
	{
		UnloadMusicStream(*m);
	}

	for (Sound* s : this->sounds) // unload sound effects
	{
		UnloadSound(*s);
	}
}

void SoundManager::PlayMusic(int id)
{
	StopMusicStream(this->currentMusic); // to reset the song to the beginning

	this->currentMusic = *this->tracks[id];

	PlayMusicStream(this->currentMusic);

}

void SoundManager::StopMusic()
{
	StopMusicStream(this->currentMusic);
}
	

void SoundManager::PlaySoundFile(SoundEffect soundEffect)
{
	switch (soundEffect)
	{
	case CoinCollect_Sound:
		PlaySound(this->CoinCollectSound);
		break;

	case StarCoinCollect_Sound:
		PlaySound(this->StarCoinCollectSound);
		break;

	case Scroll_Sound:
		PlaySound(this->ScrollSound);
		break;

	case PlayLevel_Sound:
		PlaySound(this->PlayLevelSound);
		break;

	case LevelWin_Sound:
		PlaySound(this->LevelWinSound);
		break;

	case LevelLose_Sound:
		PlaySound(this->LevelLoseSound);
		break;

	case Transition_Sound:
		PlaySound(this->TransitionSound);
		break;

	case TimesUp_Sound:
		PlaySound(this->TimesUpSound);
		break;
	default:
		break;
		
	}
}

void SoundManager::Update()
{
	UpdateMusicStream(this->currentMusic);
}
