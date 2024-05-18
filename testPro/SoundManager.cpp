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
	this->CoinSound = LoadSound("Sounds/1LineClear.mp3");
	this->StarCoinSound = LoadSound("Sounds/3LineClear.mp3");
	this->SelectLevelSound = LoadSound("Sounds/EnemyRotate.mp3");
	this->PlayLevelSound = LoadSound("Sounds/EnemySpawn.mp3");
	this->LevelWinSound = LoadSound("Sounds/Lose.mp3");
	this->LevelLoseSound = LoadSound("Sounds/Detonate.mp3");

	SetSoundVolume(this->LevelLoseSound, 0.5f);
	SetSoundVolume(this->CoinSound, 0.5f);
	SetSoundVolume(this->StarCoinSound, 0.5f);
}

SoundManager::~SoundManager()
{
	CloseAudioDevice();
	UnloadMusicStream(this->mainMenuMusic);
	UnloadMusicStream(this->inGameMusic1);
	UnloadMusicStream(this->levelSelectMusic); 
	UnloadSound(this->CoinSound);
	UnloadSound(this->StarCoinSound); 
	UnloadSound(this->SelectLevelSound); 
	UnloadSound(this->PlayLevelSound); 
	UnloadSound(this->LevelWinSound); 
	UnloadSound(this->LevelLoseSound); 

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
		PlaySound(this->CoinSound);
		break;

	case StarCoinCollect_Sound:
		PlaySound(this->StarCoinSound);
		break;

	case Scroll_Sound:
		PlaySound(this->SelectLevelSound);
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

	default:
		break;
		
	}
}

void SoundManager::Update()
{
	UpdateMusicStream(this->currentMusic);
}
