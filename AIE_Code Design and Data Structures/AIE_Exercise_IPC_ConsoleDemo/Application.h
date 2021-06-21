// Application.h
// ---------------------------------

#pragma once
#include <windows.h>

class Application
{
public:
	struct MyData
	{
		int i;
		float f;
		char c;
		bool b;
		double d;
	};

	HANDLE m_fileHandle;

	LPCWSTR m_sharedMem = L"MySharedMemory";

    Application();
    virtual ~Application();

    virtual void Run() = 0;

protected:
private:
};