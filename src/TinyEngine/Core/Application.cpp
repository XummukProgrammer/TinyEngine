#include "Application.hpp"

#include <fmt/format.h>

namespace TinyEngine
{
	void Application::OnEntry()
	{ 
		// При входе в приложение необходимо проинициализировать поля.
		fmt::print("[Application] Entry (Name: {}, Version: {})\n", 
			GetName(), 
			GetVersion());

		_window.SetUpdateHandler(std::bind(&Application::OnWindowUpdate, this));
		_window.SetDrawHandler(std::bind(&Application::OnWindowDraw, this, std::placeholders::_1));
		_window.SetEventHandler(std::bind(&Application::OnWindowEvent, this, std::placeholders::_1));
		_window.OnAppEntry();
	}

	void Application::OnQuit()
	{ 
		/*
			При выходе из приложения необходимо очистить все поля, 
			также сохранить необходимые данные в файлы/сохранку/бд.
		*/
		fmt::print("[Application] Quit\n");

		_window.OnAppQuit();
	}

	void Application::SetName(std::string_view name)
	{ 
		_name = name;

		// По умолчанию заголовок окна устанавливаем как название приложения.
		_window.SetTitle(name);
	}

	void Application::ExecWindow()
	{ 
		/*
			При запуске окна необходимо об этом проинформировать другие поля,
			а также запустить само окно.
		*/
		fmt::print("[Application] Exec Window (Title: {}, Width: {}, Height: {})\n", 
			_window.GetTitle(),
			_window.GetWidth(),
			_window.GetHeight());

		_window.Exec();
	}

	void Application::OnWindowUpdate()
	{
		// При обновлении окна необходимо об этом проинформировать другие поля.
	}

	void Application::OnWindowDraw(sf::RenderWindow& window)
	{ 
		// При отрисовке окна необходимо об этом проинформировать другие поля.
	}

	void Application::OnWindowEvent(sf::Event& event)
	{
		// При срабатывании события окна необходимо об этом проинформировать другие поля.
	}
}
