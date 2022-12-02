#include "RenderWindow.hpp"
#include "RenderObject.hpp"

#include "raylib.h"

namespace TinyEngine
{
	RenderWindow::RenderWindow()
	{
	}

	RenderWindow::~RenderWindow()
	{
	}

	void RenderWindow::Create(const RenderWindowSettings& windowSettings)
	{
		InitWindow(windowSettings.width, windowSettings.height, windowSettings.title.c_str());
		SetTargetFPS(windowSettings.maxFramerate);
	}

	bool RenderWindow::IsClosed() const
	{
		return WindowShouldClose();
	}

	void RenderWindow::Clear()
	{
		ClearBackground(RAYWHITE);
	}

	void RenderWindow::Begin()
	{
		BeginDrawing();
	}

	void RenderWindow::End()
	{
		EndDrawing();
	}

	void RenderWindow::Close()
	{
		CloseWindow();
	}
}
