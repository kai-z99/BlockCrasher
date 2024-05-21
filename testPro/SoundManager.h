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

	Music TutorialMusic;
	Music BigAndSmallMusic;
	Music BounceDungeonMusic;
	Music CubedMusic;
	Music HighPressureMusic;
	Music GridLockMusic;
	Music HappyTreeMusic;
	Music DesertedMusic;
	Music ViolentTidesMusic;
	Music VortexMusic;
	Music SwordSwingMusic;
	Music IronSteelFactoryMusic;
	
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