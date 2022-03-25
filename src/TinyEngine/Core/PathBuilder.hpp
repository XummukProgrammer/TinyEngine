#ifndef _PATH_BUILDER_HEADER_
#define _PATH_BUILDER_HEADER_

#include <string>

namespace TinyEngine
{
	class PathBuilder
	{
	public:
		// Тип папки, путь до которой нужно получить.
		enum class DirType
		{
			Root, // Корень проекта
			Bin, // Бинарники
			Assets // Ассеты
		};

	public:
		PathBuilder() = default;
		~PathBuilder() = default;

	public:
		// Путь до файла преобразовать до папки, в котором находится файл.
		std::string FilePathToDir(std::string_view path) const;

		// Получить путь до .exe файла.
		std::string GetExecuteFilePath() const;
		// Получить папку, в которой находится .exe файл.
		std::string GetExecuteFileDir() const;

		// Получить путь до папки, в котором корень проекта.
		std::string GetRootDir() const;
		// Получить путь до папки с бинарниками.
		std::string GetBinDir() const;
		// Получить путь до папки с ассетами.
		std::string GetAssetsDir() const;

		// Получить путь до папки используя тип папки.
		std::string GetDirFromType(DirType dirType) const;

		// Сформировать путь.
		std::string BuildPath(DirType dirType, std::string_view path) const;

	private:
		// Путь до .exe файла.
		mutable std::string _executeFilePath;
		// Папка, в которой находится .exe файла.
		mutable std::string _executeFileDir;
		// Папка, в которой расположен корень проекта.
		mutable std::string _rootDir;
		// Папка, в которой находятся ассеты.
		mutable std::string _assetsDir;
	};
}

#endif // _PATH_BUILDER_HEADER_
