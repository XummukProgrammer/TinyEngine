#include "FileSystem.hpp"

#include <TinyEngine/Core/Application/Application.hpp>

namespace TinyEngine
{
	void FileSystem::Init()
	{
		_exePath = std::filesystem::path(Application::GetSingleton().GetContext().GetArgv()[0]);
	}

	void FileSystem::Deinit()
	{
	}

	std::wstring FileSystem::GetDirByType(DirType type) const
	{
		const auto exeDir = GetExeDir();
		
		switch (type)
		{
		case TinyEngine::FileSystem::Root:
			return exeDir + L"../";
		case TinyEngine::FileSystem::Bin:
			return exeDir;
		case TinyEngine::FileSystem::Assets:
			return exeDir + L"../assets/";
		case TinyEngine::FileSystem::Logs:
			return exeDir + L"../logs/";
		default:
			break;
		}

		return L"";
	}

	std::wstring FileSystem::BuildPath(DirType type, std::wstring_view path)
	{
		return GetDirByType(type) + std::wstring{path};
	}
}
