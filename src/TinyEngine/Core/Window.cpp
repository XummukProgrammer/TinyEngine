#include "Window.hpp"

namespace TinyEngine
{
	void Window::OnAppEntry()
	{ 
		Create();
	}

	void Window::OnAppQuit()
	{ 
		Destroy();
		
		UnsubscribeAllUpdated();
		UnsubscribeAllDrawed();
		UnsubscribeAllEvented();
	}

	void Window::Create()
	{ 
		_renderWindow = new sf::RenderWindow(sf::VideoMode(_width, _height), _title);
		_renderWindow->setVerticalSyncEnabled(false);
		_renderWindow->setFramerateLimit(60);
	}

	void Window::Destroy()
	{ 
		delete _renderWindow;
	}

	void Window::Exec()
	{ 
		// Окно удалено или не было проинициализировано!
		if (!_renderWindow)
		{
			return;
		}

		while (_renderWindow->isOpen())
		{
			sf::Event event;
			while (_renderWindow->pollEvent(event))
			{
				// Даём возможность обрабатывать события окно, только если это событие не закрытие окна.
				if (event.type == sf::Event::Closed)
				{
					_renderWindow->close();
				}
				else
				{
					OnEvent(event);
				}
			}

			OnUpdate();

			_renderWindow->clear();
			OnDraw();
			_renderWindow->display();
		}
	}

	void Window::OnUpdate()
	{ 
		UpdatedEventParameters params;
		OnUpdated(params);
	}

	void Window::OnDraw()
	{ 
		DrawedEventParameters params(*_renderWindow);
		OnDrawed(params);
	}

	void Window::OnEvent(sf::Event& event)
	{ 
		EventedParameters params(event);
		OnEvented(params);
	}
}
