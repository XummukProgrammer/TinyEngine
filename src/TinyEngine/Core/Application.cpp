#include "Application.hpp"

#include <TinyEngine/Render/Render.hpp>

#include <filesystem>

namespace TinyEngine
{
	Application application;

	void Application::SetExecutePath(std::string_view executePath)
	{
		_executePath = executePath;
		_executeDir = std::filesystem::path(_executePath).remove_filename().generic_string();
	}

	void Application::Execute()
	{
		render.Execute();
		render.Destroy();

		LoggerDumpToFile();
	}

	void Application::LoggerDumpToFile()
	{
		logger.DumpToFile(GetLogsDir() + "dump.xml", DumpXmlFormat());
	}
}
