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

	int HEIGHT = GetSystemMetrics(SM_CYSCREEN), WIDTH = GetSystemMetrics(SM_CXSCREEN);

private:
	bool IsRunning = false;
};

