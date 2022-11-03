#include "FileSystem.hpp"

#include <TinyEngine/Core/Logger.hpp>

#include <filesystem>

namespace TinyEngine
{
	void FileSystem::SetExecutePath(std::string_view executePath)
	{
		_executePath = executePath;
		_executeDir = std::filesystem::path(_executePath).remove_filename().generic_string();

		TINY_ENGINE_INFO("FileSystem", "Success init (ExecutePath: {}, ExecuteDir: {})", _executePath, _executeDir);
	}

	std::string FileSystem::BuildPath(DirType type, std::string_view path) const
	{
		return GetDirFromType(type) + std::string{path};
	}

	std::string FileSystem::GetDirFromType(DirType type) const
	{
		switch(type)
		{
			case TinyEngine::DirType::Execute:
				return GetExecuteDir();
			case TinyEngine::DirType::Root:
				return GetRootDir();
			case TinyEngine::DirType::Assets:
				return GetAssetsDir();
			case TinyEngine::DirType::Logs:
				return GetLogsDir();
		}

		return "";
	}
}
