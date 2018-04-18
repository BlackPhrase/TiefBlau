/// @file

#pragma once

class cDataController
{
public:
	cDataController();
	~cDataController();
	
	///
	cImage *LoadImage(const tString &asPath);
	
	///
	cSound *LoadSound(const tString &asPath);
};