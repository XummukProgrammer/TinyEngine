#include "Application.hpp"

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
		, _context(std::make_shared<Context>())
	{ 
	}

	Application::ContextPtr Application::GetContext() const
	{
		return _context;
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
		_context->GetFileSystem()->SetExecuteDir(_argc, _argv);
		_context->GetFactory()->Register<Properties::Data::BoolProperty>("bool");
		_context->GetFactory()->Register<Properties::Data::IntProperty>("int");
		_context->GetFactory()->Register<Properties::Data::FloatProperty>("float");
		_context->GetFactory()->Register<Properties::Data::StringProperty>("string");
		_context->IOPropertiesLoadFromFile();

		auto weakThis = weak_from_this();

		WindowInfo windowInfo;
		windowInfo.LoadFromFile(_context);
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

		_context->OnPreInit();
	}

	void Application::OnInit()
	{ 
		_context->OnInit();
	}

	void Application::OnDeinit()
	{ 
		_context->OnDeinit();
		_context->IOPropertiesSaveToFile();
		_context.reset();
	}

	void Application::OnExecute()
	{ 
		_window->OnExecute();
	}

	void Application::OnUpdate()
	{ 
		_context->OnUpdate();
	}

	void Application::OnDraw()
	{ 
		_context->OnDraw();
	}

	void Application::OnEvent()
	{ 
		_context->OnEvent();
	}
}
