/// @file

#pragma once

struct iInputImpl;

class cInputController final
{
public:
	cInputController(iInputImpl *apImpl) : mpImpl(apImpl){}
	~cInputController();
	
	/// @return true if specified key was pressed previously and still pressed
	bool IsKeyDown(int anKey) const;
	
	/// @return true if specified key was pressed this frame
	bool KeyWasPressed(int anKey) const;
	
	/// @return true if specified key was released this frame
	bool KeyWasReleased(int anKey) const;
private:
	iInputImpl *mpImpl{nullptr};
};