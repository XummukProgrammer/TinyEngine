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
		void SetProjectPath(std::string_view projectPath);

		const std::string& GetExecutePath() const { return _executePath; }
		const std::string& GetExecuteDir() const { return _executeDir; }
		const std::string& GetProjectDir() const { return _projectDir; }
		const std::string& GetProjectPath() const { return _projectPath; }
		std::string GetRootDir() const { return _executeDir + "../"; }

		std::string GetLogsDir() const { return GetRootDir() + "logs/"; }

		std::string BuildPath(DirType type, std::string_view path) const;

	public:
		static std::string RemoveFileName(std::string_view filePath);

	private:
		std::string GetDirFromType(DirType type) const;

	private:
		std::string _executePath;
		std::string _executeDir;

		std::string _projectDir;
		std::string _projectPath;
	};
}

#endif // _FILE_SYSTEM_HEADER_
