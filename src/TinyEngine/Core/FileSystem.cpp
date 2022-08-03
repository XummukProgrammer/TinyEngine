#include "FileSystem.hpp"

#include <filesystem>

namespace TinyEngine
{
	void FileSystem::SetExecutePath(std::string_view executePath)
	{
		_executePath = executePath;
		_executeDir = std::filesystem::path(_executePath).remove_filename().generic_string();
	}

	std::string FileSystem::BuildPath(DirType type, std::string_view path) const
	{
		return GetDirFromType(type) + std::string{path};
	}

	std::string FileSystem::GetDirFromType(DirType type) const
	{
		switch(type)
		{
			case TinyEngine::FileSystem::DirType::Execute:
				return GetExecuteDir();
			case TinyEngine::FileSystem::DirType::Root:
				return GetRootDir();
			case TinyEngine::FileSystem::DirType::Assets:
				return GetAssetsDir();
			case TinyEngine::FileSystem::DirType::Logs:
				return GetLogsDir();
		}

		return "";
	}
}
