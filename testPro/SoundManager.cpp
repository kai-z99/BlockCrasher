#include "SoundManager.h"

SoundManager::SoundManager()
{
	InitAudioDevice();
	this->mainMenuMusic = LoadMusicStream("Sounds/Music.mp3");
	this->CoinSound = LoadSound("Sounds/1LineClear.mp3");
}

SoundManager::~SoundManager()
{
	CloseAudioDevice();
	UnloadMusicStream(this->mainMenuMusic);
}

void SoundManager::PlayMusic(unsigned int id)
{
	PlayMusicStream(this->mainMenuMusic);
}

void SoundManager::PlaySoundFile(unsigned int id)
{
	switch (id)
	{
	case 1:
		PlaySound(this->CoinSound);
		break;
	default:
		break;
		
	}
}

void SoundManager::Update()
{
	UpdateMusicStream(this->mainMenuMusic);
}
