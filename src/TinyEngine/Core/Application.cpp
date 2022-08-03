#include "Application.hpp"

#include <TinyEngine/Render/Render.hpp>

#include <TinyEngine/Core/Assets/AssetLoader.hpp>
#include <TinyEngine/Core/Assets/AssetTexture.hpp>

namespace TinyEngine
{
	void Application::Execute()
	{
		TINY_ENGINE_PRINT_INFO("Execute engine");

		auto& factory = GetFactory();
		factory.Register<AssetHolder>();
		factory.Register<AssetLoader>();
		factory.Register<AssetSfmlTexture>();

		GetAssets().LoadFromFile();

		auto& render = GetRender();
		render.Execute();
		render.Destroy();

		TINY_ENGINE_PRINT_INFO("Shutdown engine");

		LoggerSaveToFile();
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
}
