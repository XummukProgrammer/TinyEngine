#include "Application.hpp"

#include <TinyEngine/Render/Render.hpp>

#include <TinyEngine/Core/Assets/AssetLoader.hpp>
#include <TinyEngine/Core/Assets/AssetTexture.hpp>

#include <filesystem>

namespace TinyEngine
{
	void Application::SetExecutePath(std::string_view executePath)
	{
		_executePath = executePath;
		_executeDir = std::filesystem::path(_executePath).remove_filename().generic_string();
	}

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
