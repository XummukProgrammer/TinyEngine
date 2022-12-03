#include "RenderWindow.hpp"
#include "RenderObject.hpp"

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
		_window = std::make_unique<raylib::Window>(windowSettings.width, windowSettings.height, windowSettings.title.c_str());
		_window->SetTargetFPS(windowSettings.maxFramerate);
	}

	bool RenderWindow::IsClosed() const
	{
		return _window->ShouldClose();
	}

	void RenderWindow::Clear()
	{
		_window->ClearBackground(raylib::Color::Black());
	}

	void RenderWindow::Begin()
	{
		_window->BeginDrawing();
	}

	void RenderWindow::End()
	{
		_window->EndDrawing();
	}

	void RenderWindow::Close()
	{
		_window.reset();
	}
}
