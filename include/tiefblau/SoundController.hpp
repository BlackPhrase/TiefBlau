/// @file

#pragma once

#include "CommonTypes.hpp"

struct iSoundImpl;

class cSoundController final
{
public:
	cSoundController(iSoundImpl *apImpl) : mpImpl(apImpl){}
	~cSoundController();
	
	///
	void StartMusic(const tString &asName, float afVolume = 1.0f, bool abLoop = true);
	
	///
	void PauseMusic(bool abPause);
	
	///
	void StopMusic();
	
	///
	void StartSound(const tString &asName, float afVolume = 1.0f);
	
	///
	void StopSound(const tString &asName); // TODO: id?
	
	///
	void StopAllSounds();
	
	///
	void MuteSound(bool abMute){mbMute = abMute;}
	
	///
	bool IsMuted() const {return mbMute;}
	
	///
	void SetMasterVolume(float afVolume){mfMasterVolume = afVolume;}
	
	///
	float GetMasterVolume() const {return mfMasterVolume;}
private:
	iSoundImpl *mpImpl{nullptr};
	
	float mfMasterVolume{0.0f};
	
	bool mbMute{false};
};