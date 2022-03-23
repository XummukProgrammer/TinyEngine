#include "Window.hpp"

namespace TinyEngine
{
	void Window::OnAppEntry()
	{ 
		Create();

		_gui.OnAppEntry();
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

			_deltaTime = _clock.restart();

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

		UpdateFPSCounter();

		_gui.OnWindowUpdated(*_renderWindow.get(), _deltaTime);
	}

	void Window::OnDraw()
	{ 
		DrawedEventParameters params(*_renderWindow);
		OnDrawed(params);

		_gui.OnWindowDrawed(*_renderWindow.get());
	}

	void Window::OnEvent(sf::Event& event)
	{ 
		EventedParameters params(event);
		OnEvented(params);
	}

	void Window::UpdateFPSCounter()
	{ 
		float deltaTime = GetDeltaTime();

		if (_timerFPSCounter <= 0.f)
		{
			_lastFPSCounter = static_cast<unsigned>(1.f / deltaTime);
			_timerFPSCounter = _delayFPSCounter;
		}
		else
		{
			_timerFPSCounter -= deltaTime;

			if (_timerFPSCounter < 0.f)
			{
				_timerFPSCounter = 0.f;
			}
		}
	}
}
