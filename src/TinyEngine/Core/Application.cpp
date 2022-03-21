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

		_window.Update_Subscribe(std::bind(&Application::OnWindowUpdate, this, std::placeholders::_1));
		_window.Draw_Subscribe(std::bind(&Application::OnWindowDraw, this, std::placeholders::_1));
		_window.SFEvent_Subscribe(std::bind(&Application::OnWindowEvent, this, std::placeholders::_1));
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

	void Application::OnWindowUpdate(UpdateEventParameters& params)
	{
		// При обновлении окна необходимо об этом проинформировать другие поля.
	}

	void Application::OnWindowDraw(DrawEventParameters& params)
	{ 
		// При отрисовке окна необходимо об этом проинформировать другие поля.
	}

	void Application::OnWindowEvent(SFEventEventParameters& params)
	{
		// При срабатывании события окна необходимо об этом проинформировать другие поля.
	}
}
