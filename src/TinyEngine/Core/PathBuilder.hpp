#ifndef _PATH_BUILDER_HEADER_
#define _PATH_BUILDER_HEADER_

#include <string>

namespace TinyEngine
{
	class PathBuilder
	{
	public:
		PathBuilder() = default;
		~PathBuilder() = default;

	public:
		// Получить путь до .exe файла.
		std::string GetExecuteFilePath() const;
		// Получить папку, в которой находится .exe файл.
		std::string GetExecuteFileDir() const;
	};
}

#endif // _PATH_BUILDER_HEADER_
