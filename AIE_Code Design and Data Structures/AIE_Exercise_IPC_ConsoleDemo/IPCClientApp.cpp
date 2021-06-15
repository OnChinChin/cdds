#include"IPCClientApp.h"

#include<windows.h>
#include<iostream>
#include<conio.h>

IPCClientApp::IPCClientApp()
{

}

IPCClientApp::~IPCClientApp()
{

}

void IPCClientApp::Run()
{
    // gain access to a named shared memory block that already exists
    HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");

    if (fileHandle == nullptr)
    {
        std::cout << "Could not create file mapping object: " << GetLastError() << std::endl;
    }

    // map the memory from the shared block to a pointer we can manipulate
    MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));

    if (data == nullptr)
    {
        std::cout << "Could not map view of file: " << GetLastError() << std::endl;
        CloseHandle(fileHandle);
    }

    for(int i =0; i <)

    // write out what is in the memory block
    std::cout << "MyData = { ";
    std::cout << data->i << ", ";
    std::cout << data->f << ", ";
    std::cout << data->c << ", ";
    std::cout << data->b << ", ";
    std::cout << data->d << ", ";
    std::cout << " };" << std::endl;

    

    // wait for a keypress to close
    _getch();

    // unmap the memory block since we're done with it
    UnmapViewOfFile(data);

    // close the shared file
    CloseHandle(fileHandle);
}
