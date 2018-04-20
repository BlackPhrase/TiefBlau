/// @file

#include "SoundController.hpp"
#include "ISoundImpl.hpp"

//cSoundController::cSoundController() = default;
cSoundController::~cSoundController() = default;

/*
bool cSoundController::Init(int anFrequency, int anChannels, int anSampleSize)
{
	return mpImpl->Init(anFrequency, anChannels, anSampleSize);
};
*/

void cSoundController::StartMusic(const tString &asName, float afVolume, bool abLoop)
{
	mpImpl->StartMusic(asName, afVolume, abLoop);
};

void cSoundController::PauseMusic(bool abPause)
{
	mpImpl->PauseMusic(abPause);
};

void cSoundController::StopMusic()
{
	mpImpl->StopMusic();
};