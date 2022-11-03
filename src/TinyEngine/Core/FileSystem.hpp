#ifndef _FILE_SYSTEM_HEADER_
#define _FILE_SYSTEM_HEADER_

#include <TinyEngine/Core/Data/Singleton.hpp>
#include <TinyEngine/Core/Constants.hpp>

#include <string>

namespace TinyEngine
{
	class FileSystem final : public Singleton<FileSystem>
	{
	public:
		FileSystem() = default;
		~FileSystem() = default;

	public:
		void SetExecutePath(std::string_view executePath);
		const std::string& GetExecutePath() const { return _executePath; }
		const std::string& GetExecuteDir() const { return _executeDir; }
		std::string GetRootDir() const { return _executeDir + "../"; }
		std::string GetAssetsDir() const { return GetRootDir() + "assets/"; }
		std::string GetLogsDir() const { return GetRootDir() + "_logs/"; }

		std::string BuildPath(DirType type, std::string_view path) const;

	private:
		std::string GetDirFromType(DirType type) const;

	private:
		std::string _executePath;
		std::string _executeDir;
	};
}

#endif // _FILE_SYSTEM_HEADER_
