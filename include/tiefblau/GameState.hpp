/// @file

#pragma once

struct iGameState
{
	virtual ~iGameState() = default;
	
	virtual void OnEnter(){}
	virtual void OnLeave(){}
};