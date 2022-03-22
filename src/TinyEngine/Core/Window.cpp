﻿#include "Window.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

namespace TinyEngine
{
	void Window::OnAppEntry()
	{ 
		Create();
	}

	void Window::OnAppQuit()
	{ 
		ImGui::SFML::Shutdown();

		Destroy();
		
		UnsubscribeAllUpdated();
		UnsubscribeAllDrawed();
		UnsubscribeAllGuiDrawed();
		UnsubscribeAllEvented();
	}

	void Window::Create()
	{ 
		_renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(_width, _height), _title);
		_renderWindow->setVerticalSyncEnabled(false);
		_renderWindow->setFramerateLimit(60);

		ImGui::SFML::Init(*_renderWindow);
		auto& io = ImGui::GetIO();
		io.IniFilename = nullptr;
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
				ImGui::SFML::ProcessEvent(*_renderWindow, event);

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

			ImGui::SFML::Update(*_renderWindow, deltaClock.restart());
			OnGuiDraw();

			_renderWindow->clear();
			OnDraw();
			ImGui::SFML::Render(*_renderWindow);
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

	void Window::OnGuiDraw()
	{ 
		GuiDrawedEventParameters params;
		OnGuiDrawed(params);

		ImGui::Begin("Hello, world!");
			ImGui::Button("Look at this pretty button");
			ImGui::End();
	}

	void Window::OnEvent(sf::Event& event)
	{ 
		EventedParameters params(event);
		OnEvented(params);
	}
}
