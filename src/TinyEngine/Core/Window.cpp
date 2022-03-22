#include "Window.hpp"

namespace TinyEngine
{
	void Window::OnAppEntry()
	{ 
		Create();
	}

	void Window::OnAppQuit()
	{ 
		_gui.OnAppQuit();

		Destroy();
		
		UnsubscribeAllUpdated();
		UnsubscribeAllDrawed();
		UnsubscribeAllEvented();
	}

	void Window::Create()
	{ 
		_renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(_width, _height), _title);
		_renderWindow->setVerticalSyncEnabled(false);
		_renderWindow->setFramerateLimit(60);

		_gui.OnWindowCreated(*_renderWindow.get());
	}

	void Window::Destroy()
	{ 
		_renderWindow.reset();
	}

	void Window::Exec()
	{ 
		// Окно удалено или не было проинициализировано!
		if (!_renderWindow)
		{
			return;
		}

		sf::Clock deltaClock;

		while (_renderWindow->isOpen())
		{
			sf::Event event;
			while (_renderWindow->pollEvent(event))
			{
				_gui.OnWindowEvented(*_renderWindow.get(), event);

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

			sf::Time time = deltaClock.restart();

			OnUpdate();
			_gui.OnWindowUpdated(*_renderWindow.get(), time);

			_renderWindow->clear();
			OnDraw();
			_gui.OnWindowDrawed(*_renderWindow.get());
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
