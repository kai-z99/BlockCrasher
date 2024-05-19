#include "SoundManager.h"

SoundManager::SoundManager()
{
	InitAudioDevice();

	//Music
	this->mainMenuMusic = LoadMusicStream("Sounds/Music.mp3");
	this->inGameMusic1 = LoadMusicStream("Sounds/music_credits.mp3");
	this->levelSelectMusic = LoadMusicStream("Sounds/music_credits.mp3"); //CHANGE

	this->currentMusic = this->mainMenuMusic; // ddefault song is main menu

	//Sound Effects
	this->CoinCollectSound = LoadSound("Sounds/1LineClear.mp3");
	this->StarCoinCollectSound = LoadSound("Sounds/3LineClear.mp3");
	this->ScrollSound = LoadSound("Sounds/EnemyRotate.mp3");
	this->PlayLevelSound = LoadSound("Sounds/EnemySpawn.mp3");
	this->LevelWinSound = LoadSound("Sounds/Lose.mp3");
	this->LevelLoseSound = LoadSound("Sounds/Detonate.mp3");
	this->TransitionSound = LoadSound("Sounds/UndoRotate.mp3");

	SetSoundVolume(this->LevelLoseSound, 0.5f);
	SetSoundVolume(this->CoinCollectSound, 0.5f);
	SetSoundVolume(this->StarCoinCollectSound, 0.5f);
	SetSoundVolume(this->TransitionSound, 0.75f);
}

SoundManager::~SoundManager()
{
	CloseAudioDevice();
	UnloadMusicStream(this->mainMenuMusic);
	UnloadMusicStream(this->inGameMusic1);
	UnloadMusicStream(this->levelSelectMusic); 
	UnloadSound(this->CoinCollectSound);
	UnloadSound(this->StarCoinCollectSound); 
	UnloadSound(this->ScrollSound); 
	UnloadSound(this->PlayLevelSound); 
	UnloadSound(this->LevelWinSound); 
	UnloadSound(this->LevelLoseSound); 
	UnloadSound(this->TransitionSound);

}

void SoundManager::PlayMusic(MusicTheme theme)
{
	StopMusicStream(this->currentMusic); // to reset the song to the beginning

	switch (theme)
	{
	case MainMenu_Track:
		this->currentMusic = this->mainMenuMusic;
		break;
	case LevelSelect_Track:
		this->currentMusic = this->levelSelectMusic;
		break;

	case InGame1_Track:
		this->currentMusic = this->inGameMusic1;
		break;

	default:
		break;
	}

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
		PlaySound(TransitionSound);
		break;

	default:
		break;
		
	}
}

void SoundManager::Update()
{
	UpdateMusicStream(this->currentMusic);
}
