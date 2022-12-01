#include "RenderWindow.hpp"
#include "RenderObject.hpp"

namespace TinyEngine
{
	RenderWindow::RenderWindow()
	{
	}

	RenderWindow::~RenderWindow()
	{
		delete _renderWindow;
		_renderWindow = nullptr;
	}

	void RenderWindow::Create(const RenderWindowSettings& windowSettings)
	{
		_renderWindow = new sf::RenderWindow(sf::VideoMode(windowSettings.width, windowSettings.height), windowSettings.title);
		_renderWindow->setFramerateLimit(windowSettings.maxFramerate);
		_renderWindow->setVerticalSyncEnabled(false);
	}

	bool RenderWindow::IsClosed() const
	{
		return !_renderWindow->isOpen();
	}

	void RenderWindow::Clear()
	{
		_renderWindow->clear();
	}

	void RenderWindow::ExtractEvents()
	{
		while (_renderWindow->pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
			{
				Close();
			}
			else
			{
				OnEventReceived();
			}
		}
	}

	void RenderWindow::Draw(RenderObject* object) const
	{
		auto& sprite = object->GetSprite();
		_renderWindow->draw(sprite);
	}

	void RenderWindow::Display()
	{
		_renderWindow->display();
	}

	void RenderWindow::Close()
	{
		_renderWindow->close();
	}

	void RenderWindow::ResetClock()
	{
		_timeClock.restart();
	}

	void RenderWindow::UpdateClock()
	{
		_deltaTime = _timeClock.restart();
	}

	float RenderWindow::GetDeltaTime() const
	{
		return _deltaTime.asSeconds();
	}
}
