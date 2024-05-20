#include "SoundManager.h"

SoundManager::SoundManager()
{
	InitAudioDevice();

	//------------------------------------------------------
	//MUSIC LOADING
	//------------------------------------------------------

	this->mainMenuMusic = LoadMusicStream("Sounds/Music.mp3"); // 0
	this->tracks.push_back(&this->mainMenuMusic);

	this->levelSelectMusic = LoadMusicStream("Sounds/music_credits.mp3"); // 1
	this->tracks.push_back(&this->levelSelectMusic);

	this->inGameMusic1 = LoadMusicStream("Sounds/music_credits.mp3"); // 2
	this->tracks.push_back(&this->inGameMusic1);

	this->BigAndSmallMusic = LoadMusicStream("Sounds/BigAndSmall_Music.wav"); // 3
	SetMusicVolume(BigAndSmallMusic, 0.4f);
	SetMusicPitch(BigAndSmallMusic, 1.2f);
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
	SetMusicVolume(DesertedMusic, 0.7f);
	SetMusicPitch(DesertedMusic, 0.7f);
	this->tracks.push_back(&this->DesertedMusic);

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
	this->sounds.push_back(&this->LevelWinSound);

	this->LevelLoseSound = LoadSound("Sounds/Detonate.mp3");
	SetSoundVolume(this->LevelLoseSound, 0.5f);
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
