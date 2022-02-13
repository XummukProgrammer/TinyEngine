#ifndef _FILE_SYSTEM_MANAGER_HEADER_
#define _FILE_SYSTEM_MANAGER_HEADER_

#include <string>

namespace TinyEngine::Core
{
	enum class DirType
	{
		Configs,
		Assets
	};

	class FileSystemManager final
	{
	public:
		FileSystemManager() = default;
		~FileSystemManager() = default;

	public:
		static FileSystemManager& GetInstance();

	public:
		void SetExecuteDir(int argc, char** argv);

		std::string BuildPath(DirType dirType, const std::string& path) const;

	private:
		const std::string& GetDirPathByType(DirType dirType) const;

	private:
		std::string _executeDir;

	private:
		static inline const std::string CONFIGS_DIR_PATH = "../configs";
		static inline const std::string ASSETS_DIR_PATH = "../assets";
	};
}

#endif // _FILE_SYSTEM_MANAGER_HEADER_
