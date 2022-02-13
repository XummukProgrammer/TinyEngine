#include "Window.hpp"

#include <SFML/Graphics.hpp>

namespace TinyEngine::Core
{
	Window::Window(const WindowInfo& info)
	{ 
		_renderWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(info.width, info.height), info.title);
		_renderWindow->setFramerateLimit(info.maxFramerate);
		_renderWindow->setVerticalSyncEnabled(info.isVerticalSyncEnabled);
	}

	void Window::OnExecute()
	{ 
		while (_renderWindow->isOpen())
		{
			sf::Event event;
			while (_renderWindow->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					_renderWindow->close();
				}
				else
				{
					OnEvent();
				}
			}

			if (_renderWindow->hasFocus())
			{
				OnUpdate();
			}

			_renderWindow->clear();
			OnDraw();
			_renderWindow->display();
		}
	}

	void Window::OnUpdate()
	{ 
		if (_onUpdateCallback)
		{
			_onUpdateCallback();
		}
	}

	void Window::OnDraw()
	{ 
		if (_onDrawCallback)
		{
			_onDrawCallback();
		}
	}

	void Window::OnEvent()
	{ 
		if (_onEventCallback)
		{
			_onEventCallback();
		}
	}
}
