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
	}

	bool RenderWindow::IsClosed() const
	{
		return true;
	}

	void RenderWindow::Clear()
	{
	}

	void RenderWindow::ExtractEvents()
	{
	}

	void RenderWindow::Draw(RenderObject* object) const
	{
	}

	void RenderWindow::Display()
	{
	}

	void RenderWindow::Close()
	{
	}

	void RenderWindow::ResetClock()
	{
	}

	void RenderWindow::UpdateClock()
	{
	}

	float RenderWindow::GetDeltaTime() const
	{
		return 0.f;
	}
}
