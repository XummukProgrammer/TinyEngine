#include "Application.hpp"

#include <TinyEngine/Core/Window.hpp>
#include <TinyEngine/Core/WindowLoader.hpp>
#include <TinyEngine/Core/LoaderManager.hpp>
#include <TinyEngine/Core/FileSystemManager.hpp>

namespace TinyEngine::Core
{
	Application::Application(ApplicationDelegate& delegate, int argc, char** argv)
		: _delegate(delegate)
		, _argc(argc)
		, _argv(argv)
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
		FileSystemManager::GetInstance().SetExecuteDir(_argc, _argv);

		auto weakThis = weak_from_this();

		WindowInfo windowInfo;
		WindowLoader windowLoader(&windowInfo);
		LoaderManager::GetInstance().LoadFromFile(&windowLoader);
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
