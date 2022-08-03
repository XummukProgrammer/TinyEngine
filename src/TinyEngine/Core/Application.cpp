#include "Application.hpp"

#include <TinyEngine/Render/Render.hpp>

#include <TinyEngine/Core/Assets/AssetLoader.hpp>
#include <TinyEngine/Core/Assets/AssetTexture.hpp>

namespace TinyEngine
{
	Application& Application::Init(int argc, char* argv[], const RenderWindowSettings& windowSettings, ApplicationDelegatePtr&& delegate)
	{
		GetFileSystem().SetExecutePath(argv[0]);
		_delegate = std::move(delegate);

		switch (windowSettings.renderType)
		{
			case RenderType::Sfml:
				GetRender().CreateSfmlWindow(windowSettings);
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
		GetLogger().SaveToFile();
	}

	void Application::Close()
	{
		GetRender().Close();
	}

	void Application::OnInit()
	{
		auto& factory = GetFactory();
		factory.Register<AssetHolder>();
		factory.Register<AssetLoader>();
		factory.Register<AssetSfmlTexture>();

		GetAssets().LoadFromFile();

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

		GetRender().Destroy();

		LoggerSaveToFile();
	}

	void Application::OnProcess()
	{
		GetRender().Execute();
	}
}
