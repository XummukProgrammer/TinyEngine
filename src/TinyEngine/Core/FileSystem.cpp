#include "FileSystem.hpp"

#include <fmt/format.h>

#include <filesystem>

namespace TinyEngine::Core
{
	const std::map<DirType, std::string> FileSystem::DIR_PATHS =
	{
		{ DirType::Configs, "../configs" },
		{ DirType::Assets, "../assets" }
	};

	void FileSystem::SetExecuteDir(int argc, char** argv)
	{ 
		auto executePath = std::filesystem::path(std::string{argv[0]});
		_executeDir = executePath.remove_filename().generic_string();
	}

	std::string FileSystem::BuildPath(DirType dirType, const std::string& path) const
	{
		return fmt::format("{}{}/{}", _executeDir, GetDirPathByType(dirType), path);
	}

	const std::string& FileSystem::GetDirPathByType(DirType dirType) const
	{
		auto it = DIR_PATHS.find(dirType);

		if (it != DIR_PATHS.end())
		{
			return it->second;
		}

		static std::string empty;
		return empty;
	}
}
