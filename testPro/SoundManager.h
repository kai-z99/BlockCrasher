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

	Sound CoinCollectSound;
	Sound StarCoinCollectSound;
	Sound ScrollSound;
	Sound PlayLevelSound;
	Sound LevelWinSound;
	Sound LevelLoseSound;
	Sound TransitionSound;

};