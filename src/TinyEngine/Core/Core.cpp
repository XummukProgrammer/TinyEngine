#include "Core.hpp"

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
	void Core::Exec()
	{
		{
			// Последовательный запуск методов, формирующие конвейер приложения.
			auto& application = Application::GetInstance();
			application.OnEntry();
			application.ExecWindow();
			application.OnQuit();
		}

		Application::ResetInstance();
	}
}
