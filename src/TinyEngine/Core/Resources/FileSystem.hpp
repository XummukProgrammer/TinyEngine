#ifndef _FILE_SYSTEM_HEADER_
#define _FILE_SYSTEM_HEADER_

#include <filesystem>
#include <string>

namespace TinyEngine
{
	class FileSystem
	{
	public:
		enum DirType
		{
			Root,
			Bin,
			Assets,
			Logs
		};

	public:
		FileSystem() = default;
		~FileSystem() = default;

	public:
		void Init();
		void Deinit();

	public:
		std::wstring GetExePath() const { return _exePath.generic_wstring(); }
		std::wstring GetExeDir() const { return _exePath.remove_filename().generic_wstring(); }
		std::wstring GetDirByType(DirType type) const;
		std::wstring BuildPath(DirType type, std::wstring_view path) const;

	private:
		mutable std::filesystem::path _exePath;
	};
}

#endif // _FILE_SYSTEM_HEADER_
