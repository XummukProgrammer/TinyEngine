#include "Application.hpp"

#include <fmt/format.h>

namespace TinyEngine
{
	void Application::OnEntry()
	{ 
		/*
			При входе в приложение необходимо проинициализировать
			системные поля и классы.
		*/
		fmt::print("[Application] Entry (Name: {}, Version: {})\n", GetName(), GetVersion());
	}

	void Application::OnQuit()
	{ 
		/*
			При выходе из приложения необходимо очистить все
			системные поля и классы, также сохранить необходимые данные в файлы/сохранку/бд.
		*/
		fmt::print("[Application] Quit\n", GetName());
	}
}
