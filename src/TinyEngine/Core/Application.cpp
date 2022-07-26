#include "Application.hpp"

#include <TinyEngine/Render/Render.hpp>

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
		TINY_ENGINE_INFO("Execute engine");

		auto& render = GetRender();
		render.Execute();
		render.Destroy();

		TINY_ENGINE_INFO("Shutdown engine");

		LoggerDumpToFile();
	}

	void Application::LoggerDumpToFile()
	{
		TINY_ENGINE_INFO("Dump logger messages");
		GetLogger().DumpToFile(GetLogsDir() + "dump.xml", DumpXmlFormat());
	}

	void Application::Close()
	{
		GetRender().Close();
	}
}
