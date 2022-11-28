#include "FileSystem.hpp"

#include <TinyEngine/Core/Logger.hpp>

#include <filesystem>

namespace TinyEngine
{
	void FileSystem::SetExecutePath(std::string_view executePath)
	{
		_executePath = executePath;
		_executeDir = RemoveFileName(_executePath);
	}

	void FileSystem::SetProjectPath(std::string_view projectPath)
	{
		_projectPath = projectPath;
		_projectDir = RemoveFileName(_projectPath);
	}

	std::string FileSystem::BuildPath(DirType type, std::string_view path) const
	{
		return GetDirFromType(type) + std::string{path};
	}

	std::string FileSystem::RemoveFileName(std::string_view filePath)
	{
		return std::filesystem::path(filePath).remove_filename().generic_string();
	}

	std::string FileSystem::GetDirFromType(DirType type) const
	{
		switch (type)
		{
		case DirType::Logs:
			return GetLogsDir();
		case DirType::Project:
			return GetProjectDir();
		}

		return "";
	}
}
