#include "Application.hpp"

#include <TinyEngine/Core/Debug.hpp>
#include <TinyEngine/Core/FileSystem.hpp>
#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Assets/Asset.hpp>
#include <TinyEngine/Core/Assets/AssetHolder.hpp>
#include <TinyEngine/Core/Assets/AssetLoader.hpp>
#include <TinyEngine/Core/Assets/AssetTexture.hpp>
#include <TinyEngine/Render/Render.hpp>
#include <TinyEngine/Gui/Gui.hpp>
#include <TinyEngine/Data/Factory.hpp>

namespace TinyEngine
{
	Application& Application::Init(int argc, char* argv[], const RenderWindowSettings& windowSettings, ApplicationDelegateUniquePtr&& delegate)
	{
		GetFileSystem()->SetExecutePath(argv[0]);
		_delegate = std::move(delegate);

		switch (windowSettings.renderType)
		{
			case RenderType::Sfml:
				GetRender()->CreateSfmlWindow(windowSettings);
				break;
		}

		return *this;
	}

	void Application::Execute()
	{
		TINY_ENGINE_PRINT_INFO("Execute engine");

		OnInit();
		OnProcess();
		OnDeinit();
	}

	void Application::LoggerSaveToFile()
	{
		TINY_ENGINE_PRINT_INFO("Logger save to file");
		GetLogger()->SaveToFile();
	}

	void Application::Close()
	{
		GetRender()->Close();
	}

	DebugPtr Application::GetDebug()
	{
		return Debug::GetInstance();
	}

	LoggerPtr Application::GetLogger()
	{
		return Logger::GetInstance();
	}

	RenderPtr Application::GetRender()
	{
		return Render::GetInstance();
	}

	GuiPtr Application::GetGui()
	{
		return Gui::GetInstance();
	}

	FactoryPtr Application::GetFactory()
	{
		return Factory::GetInstance();
	}

	AssetsPtr Application::GetAssets()
	{
		return Assets::GetInstance();
	}

	FileSystemPtr Application::GetFileSystem()
	{
		return FileSystem::GetInstance();
	}

	void Application::OnInit()
	{
		GetAssets()->LoadFromFile();

		if (_delegate)
		{
			_delegate->OnInit();
		}
	}

	void Application::OnDeinit()
	{
		TINY_ENGINE_PRINT_INFO("Shutdown engine");

		if (_delegate)
		{
			_delegate->OnDeinit();
		}

		GetRender()->Destroy();

		LoggerSaveToFile();
	}

	void Application::OnProcess()
	{
		GetRender()->Execute();
	}
}
