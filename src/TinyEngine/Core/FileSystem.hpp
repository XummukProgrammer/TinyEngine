#ifndef _FILE_SYSTEM_HEADER_
#define _FILE_SYSTEM_HEADER_

#include <TinyEngine/Utils/Singleton.hpp>

#include <string>
#include <map>

namespace TinyEngine::Core
{
	enum class DirType
	{
		Configs,
		Assets,
		Data
	};

	class FileSystem final : public Utils::Singleton<FileSystem>
	{
	public:
		FileSystem() = default;
		~FileSystem() = default;

	public:
		void SetExecuteDir(int argc, char** argv);

		std::string BuildPath(DirType dirType, const std::string& path) const;

	private:
		const std::string& GetDirPathByType(DirType dirType) const;

	private:
		std::string _executeDir;

	private:
		static const std::map<DirType, std::string> DIR_PATHS;
	};
}

#endif // _FILE_SYSTEM_MANAGER_HEADER_
