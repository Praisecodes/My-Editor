#pragma once
#include <Windows.h>

class Window
{
public:
	bool Create();
	bool isRunning();
	bool EndProcess();
	bool show();

	//virtual functions
	virtual void Update() = 0;

private:
	bool IsRunning = false;
};

