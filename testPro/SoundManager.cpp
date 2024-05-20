#include "SoundManager.h"

SoundManager::SoundManager()
{
	InitAudioDevice();

	//Music
	this->mainMenuMusic = LoadMusicStream("Sounds/Music.mp3");
	this->inGameMusic1 = LoadMusicStream("Sounds/music_credits.mp3");
	this->levelSelectMusic = LoadMusicStream("Sounds/music_credits.mp3"); //CHANGE

	this->BigAndSmallMusic = LoadMusicStream("Sounds/BigAndSmall_Music.wav");
	SetMusicVolume(BigAndSmallMusic, 0.4f);
	SetMusicPitch(BigAndSmallMusic, 1.2f);

	this->BounceDungeon_Music = LoadMusicStream("Sounds/BounceDungeon_Music.wav");

	this->CubedMusic = LoadMusicStream("Sounds/Cubed_Music.mp3");
	SetMusicVolume(this->CubedMusic, 0.25f);
	SetMusicPitch(this->CubedMusic, 0.88f);

	this->GridLockMusic = LoadMusicStream("Sounds/GridLock_Music.mp3");
	
	this->DesertedMusic = LoadMusicStream("Sounds/Deserted_Music.wav");
	SetMusicVolume(DesertedMusic, 0.7f);
	SetMusicPitch(DesertedMusic, 0.7f);

	this->currentMusic = this->mainMenuMusic; // ddefault song is main menu

	//Sound Effects
	this->CoinCollectSound = LoadSound("Sounds/1LineClear.mp3");
	this->StarCoinCollectSound = LoadSound("Sounds/3LineClear.mp3");
	this->ScrollSound = LoadSound("Sounds/EnemyRotate.mp3");
	this->PlayLevelSound = LoadSound("Sounds/EnemySpawn.mp3");
	this->LevelWinSound = LoadSound("Sounds/Lose.mp3");
	this->LevelLoseSound = LoadSound("Sounds/Detonate.mp3");
	this->TransitionSound = LoadSound("Sounds/UndoRotate.mp3");
	this->TimesUpSound = LoadSound("Sounds/Beep.mp3");

	SetSoundVolume(this->LevelLoseSound, 0.5f);
	SetSoundVolume(this->CoinCollectSound, 0.5f);
	SetSoundVolume(this->StarCoinCollectSound, 0.5f);
	SetSoundVolume(this->TransitionSound, 0.75f);
	SetSoundVolume(this->TimesUpSound, 1.5f);


	
}

SoundManager::~SoundManager()
{
	CloseAudioDevice();

	UnloadMusicStream(this->mainMenuMusic);
	UnloadMusicStream(this->inGameMusic1);
	UnloadMusicStream(this->levelSelectMusic); 
	UnloadMusicStream(this->DesertedMusic);
	UnloadMusicStream(this->GridLockMusic);
	UnloadMusicStream(this->BigAndSmallMusic);
	UnloadMusicStream(this->BounceDungeon_Music);
	UnloadMusicStream(this->CubedMusic);

	UnloadSound(this->CoinCollectSound);
	UnloadSound(this->StarCoinCollectSound); 
	UnloadSound(this->ScrollSound); 
	UnloadSound(this->PlayLevelSound); 
	UnloadSound(this->LevelWinSound); 
	UnloadSound(this->LevelLoseSound); 
	UnloadSound(this->TransitionSound);
	UnloadSound(this->TimesUpSound);

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

	case BigAndSmall_Track:
		this->currentMusic = this->BigAndSmallMusic;
		break;

	case Deserted_Track:
		this->currentMusic = this->DesertedMusic;
		break;

	case GridLock_Track:
		this->currentMusic = this->GridLockMusic;
		break;

	case BounceDungeon_Track:
		this->currentMusic = this->BounceDungeon_Music;
		break;

	case Cubed_Track:
		this->currentMusic = this->CubedMusic;
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
