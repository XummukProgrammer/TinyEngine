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

		_allAssets.OnAppEntry();

		_window.SubscribeUpdated(std::bind(&Application::OnWindowUpdated, this, std::placeholders::_1));
		_window.SubscribeDrawed(std::bind(&Application::OnWindowDrawed, this, std::placeholders::_1));
		_window.SubscribeEvented(std::bind(&Application::OnWindowEvented, this, std::placeholders::_1));

		_window.GetGui().SubscribeRenderer(std::bind(&Application::OnGuiRenderer, this, std::placeholders::_1));

		_window.OnAppEntry();

		_pathBuilder.GetExecuteFileDir();
	}

	void Application::OnQuit()
	{ 
		/*
			При выходе из приложения необходимо очистить все поля, 
			также сохранить необходимые данные в файлы/сохранку/бд.
		*/
		fmt::print("[Application] Quit\n");

		_window.OnAppQuit();

		_allAssets.OnAppQuit();
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

	void Application::OnWindowUpdated(UpdatedEventParameters& params)
	{
		// При обновлении окна необходимо об этом проинформировать другие поля.
	}

	void Application::OnWindowDrawed(DrawedEventParameters& params)
	{ 
		// При отрисовке окна необходимо об этом проинформировать другие поля.
	}

	void Application::OnWindowEvented(EventedParameters& params)
	{
		// При срабатывании события окна необходимо об этом проинформировать другие поля.
	}

	void Application::OnGuiRenderer(GuiRenderedEventParameters& params)
	{ 
		// При отрисовке графического интерфейса необходимо об этом проинформировать другие поля.
	}
}
