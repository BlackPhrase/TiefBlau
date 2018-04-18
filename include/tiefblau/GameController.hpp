/// @file

#pragma once

struct iGameState;
class cDisplayController;
class cSoundController;

class cGameController
{
public:
	cGameController(cDisplayController *apDisplayController, cSoundController *apSoundController)
		: mpDisplayController(apDisplayController), mpSoundController(apSoundController){}
	~cGameController();
	
	void PushState(iGameState *apState);
	void PopState();
private:
	cDisplayController *mpDisplayController{nullptr};
	cSoundController *mpSoundController{nullptr};
	
	iGameState *mpCurrentState{nullptr};
};