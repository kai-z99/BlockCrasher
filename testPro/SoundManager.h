#pragma once
#include <vector>
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
	std::vector<Music> tracks; // beta

	Music mainMenuMusic;
	Music levelSelectMusic;

	Music inGameMusic1;
	Music BigAndSmallMusic;
	Music BounceDungeon_Music;
	Music CubedMusic;
	Music GridLockMusic;
	Music DesertedMusic;
	
	

	Sound CoinCollectSound;
	Sound StarCoinCollectSound;
	Sound ScrollSound;
	Sound PlayLevelSound;
	Sound LevelWinSound;
	Sound LevelLoseSound;
	Sound TransitionSound;
	Sound TimesUpSound;

};