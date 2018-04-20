/// @file

#pragma once

#include <list>
#include "CommonTypes.hpp"

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
	
	///
	void SetBackground(const tString &asBackground){msBackground = asBackground;}
	
	///
	const tString &GetBackground() const {return msBackground;}
private:
	tActorList mlstActors;
	
	tString msBackground{""};
};