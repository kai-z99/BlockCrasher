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
}

void SoundManager::PlayMusic(MusicTheme theme)
{
	StopMusicStream(this->currentMusic); // to reset the song to the beginning

	switch (theme)
	{
	case MainMenu:
		this->currentMusic = this->mainMenuMusic;
		break;
	case ChooseLevel:
		this->currentMusic = this->levelSelectMusic;
		break;

	case InGame1:
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
	case CoinCollect:
		PlaySound(this->CoinSound);
		break;

	case StarCoinCollect:
		PlaySound(this->StarCoinSound);
		break;

	case SelectLevel:
		PlaySound(this->SelectLevelSound);
		break;

	case PlayLevel:
		PlaySound(this->PlayLevelSound);
		break;

	case LevelWin:
		PlaySound(this->LevelWinSound);
		break;

	case LevelLose:
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
