#include "Application.hpp"

namespace TinyEngine::Core
{
	Application::Application(ApplicationDelegate& delegate)
		: _delegate(delegate)
	{ 
	}

	void Application::Start()
	{
		OnPreInit();
		OnInit();

		OnExecute();

		OnDeinit();
	}

	void Application::OnPreInit()
	{ 
		_delegate.OnPreInit();
	}

	void Application::OnInit()
	{ 
		_delegate.OnInit();
	}

	void Application::OnDeinit()
	{ 
		_delegate.OnDeinit();
	}

	void Application::OnExecute()
	{ 
	
	}
}
