#include "Application.hpp"

#include <TinyEngine/Core/Window.hpp>

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
		auto weakThis = weak_from_this();

		WindowInfo windowInfo;
		_window = std::make_shared<Window>(windowInfo);
		_window->SetOnUpdateCallback([weakThis]()
		{
			if (auto sharedThis = weakThis.lock())
			{
				sharedThis->OnUpdate();
			}
		});
		_window->SetOnDrawCallback([weakThis]()
		{
			if (auto sharedThis = weakThis.lock())
			{
				sharedThis->OnDraw();
			}
		});
		_window->SetOnEventCallback([weakThis]()
		{
			if (auto sharedThis = weakThis.lock())
			{
				sharedThis->OnEvent();
			}
		});

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
		_window->OnExecute();
	}

	void Application::OnUpdate()
	{ 
		_delegate.OnUpdate();
	}

	void Application::OnDraw()
	{ 
		_delegate.OnDraw();
	}

	void Application::OnEvent()
	{ 
		_delegate.OnEvent();
	}
}
