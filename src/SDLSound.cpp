/// @file

#include <SDL_mixer.h>

#include "SDLSound.hpp"

cSoundSDL::cSoundSDL() = default;

cSoundSDL::~cSoundSDL()
{
	Mix_CloseAudio();
};

bool cSoundSDL::Init(int anFrequency, int anChannels, int anSampleSize)
{
	if(Mix_OpenAudio(anFrequency, MIX_DEFAULT_FORMAT, anChannels, anSampleSize) == -1)
		return false;
	
	return true;
};

void cSoundSDL::StartMusic(const tString &asName, float afVolume, bool abLoop)
{
	Mix_Music *pMusic = Mix_LoadMUS(asName.c_str());
	
	if(!pMusic)
		return;
	
	if(!Mix_PlayingMusic())
		if(abLoop)
			Mix_PlayMusic(pMusic, -1);
		else
			Mix_PlayMusic(pMusic, 0);
	
	//Mix_FreeMusic(pMusic);
};

void cSoundSDL::PauseMusic(bool abPause)
{
	if(abPause)
		Mix_PauseMusic();
	else
		if(Mix_PausedMusic())
			Mix_ResumeMusic();
};

void cSoundSDL::StopMusic()
{
	Mix_HaltMusic();
};