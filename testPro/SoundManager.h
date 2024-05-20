#pragma once
#include <vector>
#include <raylib.h>
#include "SoundEffect.h"


class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	
	void PlayMusic(int id);
	void StopMusic();
	void PlaySoundFile(SoundEffect soundEffect);
	

	void Update();

private:
	Music currentMusic;
	std::vector<Music*> tracks; // beta

	Music mainMenuMusic;
	Music levelSelectMusic;

	Music inGameMusic1;
	Music BigAndSmallMusic;
	Music BounceDungeonMusic;
	Music CubedMusic;
	Music GridLockMusic;
	Music DesertedMusic;
	
	
	std::vector<Sound*> sounds;

	Sound CoinCollectSound;
	Sound StarCoinCollectSound;
	Sound ScrollSound;
	Sound PlayLevelSound;
	Sound LevelWinSound;
	Sound LevelLoseSound;
	Sound TransitionSound;
	Sound TimesUpSound;

};