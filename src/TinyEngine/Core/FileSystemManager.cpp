#include "FileSystemManager.hpp"

#include <fmt/format.h>

#include <filesystem>

namespace TinyEngine::Core
{
	FileSystemManager& FileSystemManager::GetInstance()
	{
		static FileSystemManager fileSystemManager;
		return fileSystemManager;
	}

	void FileSystemManager::SetExecuteDir(int argc, char** argv)
	{ 
		auto executePath = std::filesystem::path(std::string{argv[0]});
		_executeDir = executePath.remove_filename().generic_string();
	}

	std::string FileSystemManager::BuildPath(DirType dirType, const std::string& path) const
	{
		return fmt::format("{}{}/{}", _executeDir, GetDirPathByType(dirType), path);
	}

	const std::string& FileSystemManager::GetDirPathByType(DirType dirType) const
	{
		switch (dirType)
		{
			case DirType::Configs:
				return CONFIGS_DIR_PATH;
				break;

			case DirType::Assets:
				return ASSETS_DIR_PATH;
				break;
		}

		static std::string empty;
		return empty;
	}
}
