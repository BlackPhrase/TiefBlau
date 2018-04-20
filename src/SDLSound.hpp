/// @file

#pragma once

#include "ISoundImpl.hpp"

class cSoundSDL final : public iSoundImpl
{
public:
	cSoundSDL();
	~cSoundSDL();
	
	bool Init(int anFrequency, int anChannels, int anSampleSize) override;
	
	void StartMusic(const tString &asName, float afVolume, bool abLoop) override;
	void PauseMusic(bool abPause) override;
	void StopMusic() override;
private:
};