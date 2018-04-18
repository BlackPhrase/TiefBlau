/// @file

#pragma once

class cCamera
{
public:
	cCamera();
	~cCamera();
	
	void Update(float afTimeStep);
	
	///
	void StartShake(float afTime, float afForce);
	
	///
	//void StopShake(afTime);
	
	///
	void ClearShake();
	
	/// @return true if screen shake is currently active
	bool ShakeActive() const {return mbShakeActive;}
	
	///
	void FadeIn(float afDuration);
	
	///
	void FadeOut(float afDuration);
	
	///
	void ZoomIn();
	void ZoomOut();
private:
	float mfShakeTime{0.0f};
	float mfShakeForce{0.0f};
	
	bool mbShakeActive{false};
};