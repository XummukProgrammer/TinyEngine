#include "Core.hpp"

namespace TinyEngine
{
	Application Core::s_application;

	void Core::Exec()
	{
		s_application.OnEntry();

		s_application.OnQuit();
	}
}
