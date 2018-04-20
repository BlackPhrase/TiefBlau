/// @file

#pragma once

#include "CommonTypes.hpp"

class cActor
{
public:
	cActor() : msName(L"KID"), msImage(""){}
	cActor(const tWString &asName, const tString &asImage);
	~cActor();
	
	/// Set a new name
	void SetName(const tWString &asName){msName = asName;}
	
	/// @return current name
	const tWString &GetName() const {return msName;}
	
	/// Set a new image set representing the actor
	void SetImage(const tString &asImage){msImage = asImage;}
	
	/// @return current image set used
	const tString &GetImage() const {return msImage;}
	
	/// Set a new pose
	void SetPose(const tString &asPose){msPose = asPose;}
	
	/// @return current pose
	const tString &GetPose() const {return msPose;}
	
	///
	void SetPosition(const tVec3n &avPos){mvPos = avPos;}
	
	///
	const tVec3n &GetPosition() const {return mvPos;}
private:
	tWString msName{L""}; ///< Display name (supports wide characters)
	tString msImage{""}; ///< Current image
	tString msPose{""}; ///< Current pose type
	
	tVec3n mvPos{0};
};