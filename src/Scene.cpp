/// @file

#include "Scene.hpp"

cScene::cScene() = default;
cScene::~cScene() = default;
/*
{
	for(It : mlstActors)
	{
		delete It;
		mlstActors.erase(It);
	};
};
*/

void cScene::Update(float afTimeStep)
{
	//for(It : mlstActors)
		//It->Update(afTimeStep);
};

cActor *cScene::CreateActor()
{
	cActor *pActor = nullptr; //mlstActors.emplace_back();
	return pActor;
};

void cScene::DestroyActor(cActor *apActor)
{
	//mlstActors.erase(apActor);
};