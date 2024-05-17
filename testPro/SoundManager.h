#pragma once
#include <raylib.h>
#include "SoundEffect.h"
#include "MusicTheme.h"

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	
	void PlayMusic(MusicTheme theme);
	void StopMusic();
	void PlaySoundFile(SoundEffect soundEffect);
	

	void Update();

private:
	Music currentMusic;

	Music mainMenuMusic;
	Music levelSelectMusic;
	Music inGameMusic1;

	Sound CoinSound;
	Sound StarCoinSound;
	Sound SelectLevelSound;
	Sound PlayLevelSound;
	Sound LevelWinSound;
	Sound LevelLoseSound;

};