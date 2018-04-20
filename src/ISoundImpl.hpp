/// @file

#pragma once

#include "CommonTypes.hpp"

struct iSoundImpl
{
	///
	virtual bool Init(int anFrequency, int anChannels, int anSampleSize) = 0;
	
	///
	virtual void StartMusic(const tString &asName, float afVolume, bool abLoop) = 0;
	
	///
	virtual void PauseMusic(bool abPause) = 0;
	
	///
	virtual void StopMusic() = 0;
};