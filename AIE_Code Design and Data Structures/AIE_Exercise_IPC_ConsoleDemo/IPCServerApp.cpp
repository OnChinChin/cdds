#include"IPCServerApp.h"
#include"Application.h"

#include<windows.h>
#include<iostream>
#include<conio.h>


IPCServerApp::IPCServerApp()
{

}
IPCServerApp::~IPCServerApp()
{

}
void IPCServerApp::Run()
{
    bool shouldClose = false;
    while (!shouldClose)
    {
        MyData myData = { 99, 7.56f, 'A', true, 69.42 };


        // open a named shared memory block
        m_fileHandle = CreateFileMapping(
            INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
            nullptr, // optional security attributes
            PAGE_READWRITE, // read/write access control
            0,
            sizeof(MyData), // size of the memory block, 
            m_sharedMem);

        if (m_fileHandle == nullptr)
        {
            std::cout << "Could not create file mapping object: " <<
                GetLastError() << std::endl;
        }

        MyData* data = (MyData*)MapViewOfFile(m_fileHandle,
            FILE_MAP_ALL_ACCESS,
            0,
            0,
            sizeof(MyData));

        if (data == nullptr)
        {
            std::cout << "Could not map view of file: " <<
                GetLastError() << std::endl;

            CloseHandle(m_fileHandle);
        }

        *data = myData;


        _getch();
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            shouldClose = true;
        }



        UnmapViewOfFile(data);


        CloseHandle(m_fileHandle);
    }
}