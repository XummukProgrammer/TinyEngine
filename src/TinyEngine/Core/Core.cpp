#include "Core.hpp"

namespace TinyEngine
{
	Application* Core::s_application = new Application();

	void Core::Exec()
	{
		// Последовательный запуск методов, формирующие конвейер приложения.
		s_application->OnEntry();
		s_application->ExecWindow();
		s_application->OnQuit();
		delete s_application;
	}
}
