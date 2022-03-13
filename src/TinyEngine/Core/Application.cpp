﻿#include "Application.hpp"

#include <TinyEngine/Core/Window.hpp>
#include <TinyEngine/Core/FileSystem.hpp>
#include <TinyEngine/Core/Context.hpp>
#include <TinyEngine/Properties/Properties.hpp>
#include <TinyEngine/Properties/Data/BoolProperty.hpp>
#include <TinyEngine/Properties/Data/IntProperty.hpp>
#include <TinyEngine/Properties/Data/FloatProperty.hpp>
#include <TinyEngine/Properties/Data/StringProperty.hpp>

namespace TinyEngine::Core
{
	Application::Application(int argc, char** argv)
		: _argc(argc)
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
		FileSystem::GetInstance().SetExecuteDir(_argc, _argv);

		Factory::GetInstance().Register<Properties::Data::BoolProperty>();
		Factory::GetInstance().Register<Properties::Data::IntProperty>();
		Factory::GetInstance().Register<Properties::Data::FloatProperty>();
		Factory::GetInstance().Register<Properties::Data::StringProperty>();

		Context::GetInstance().GetIOProperties()->LoadFromFile(Context::GetInstance().GetIOPropertiesPath());

		auto weakThis = weak_from_this();

		WindowInfo windowInfo;
		windowInfo.LoadFromFile();
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

		Context::GetInstance().OnPreInit();
	}

	void Application::OnInit()
	{ 
		Context::GetInstance().OnInit();
	}

	void Application::OnDeinit()
	{ 
		Context::GetInstance().OnDeinit();
		Context::GetInstance().GetIOProperties()->SaveToFile(Context::GetInstance().GetIOPropertiesPath());
	}

	void Application::OnExecute()
	{ 
		_window->OnExecute();
	}

	void Application::OnUpdate()
	{ 
		Context::GetInstance().OnUpdate();
	}

	void Application::OnDraw()
	{ 
		Context::GetInstance().OnDraw();
	}

	void Application::OnEvent()
	{ 
		Context::GetInstance().OnEvent();
	}
}
