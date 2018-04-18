/// @file

#pragma once

#include <list>

class cActor;
using tActorList = std::list<cActor*>;

class cScene
{
public:
	cScene();
	~cScene();
	
	void Update(float afTimeStep);
	
	///
	cActor *CreateActor(/*const tWString &asName*/);
	
	///
	void DestroyActor(cActor *apActor);
private:
	tActorList mlstActors;
};