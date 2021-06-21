#include "EntityDisplayApp.h"
#include"Application.h"

#include "raylib.h"


EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) :
	Application(screenWidth, screenHeight, "Display App")
{

}

EntityDisplayApp::~EntityDisplayApp()
{

}

void EntityDisplayApp::Startup()
{
	//move this into application //maybe
	m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, m_sharedMem);

	data = (Entity*)MapViewOfFile(m_fileHandle, 0, 0, 0, sizeof(Entity));

	//load file
	//load data
	
}

void EntityDisplayApp::Shutdown()
{

	UnmapViewOfFile(data);
	CloseHandle(m_fileHandle);
	//unmap data
	//close file
}

void EntityDisplayApp::Update(float deltaTime)
{
	
	//update


	//looptrhough and read data and update entities 



	//shutodnw

	DrawText("Waiting for Editor App to open", 150, 200, 32, LIGHTGRAY);

}

void EntityDisplayApp::Draw()
{

	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw entities
	for (auto& entity : m_entities) {

		DrawRectanglePro(
			Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
			Vector2{ entity.size / 2, entity.size / 2 }, // origin
			entity.rotation,
			Color{ entity.r, entity.g, entity.b, 255 });
	}

	if

	//somehow check if file is read if not draw "waiting for editier" aka if no file display this if there is a file display the for loop above

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);
	

	EndDrawing();
}