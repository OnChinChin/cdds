#pragma once
#include <raylib.h>
#include "FixWindows.h"
#include "Entity.h"




class Application
{
public:

	HANDLE m_fileHandle;

	LPCWSTR m_sharedMem = L"MySharedMemory";

	Entity* data;

	Application(int screenWidth, int screenHeight, const char *windowTitle);
	virtual ~Application();

	void Run();

	virtual void Startup() = 0;
	virtual void Shutdown() = 0;

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

protected:

	int m_screenWidth;
	int m_screenHeight;
	const char* m_windowTitle;
	

private:
};
