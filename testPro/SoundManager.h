#pragma once
#include <raylib.h>

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	
	void PlayMusic(unsigned int id);
	void PlaySoundFile(unsigned int id);

	void Update();

private:
	Music currentMusic;


	Music mainMenuMusic;
	Sound CoinSound;

};