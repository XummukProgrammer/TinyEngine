#ifndef _INTERFACE_LOADER_HEADER_
#define _INTERFACE_LOADER_HEADER_

#include <pugixml.hpp>
#include <string>

namespace TinyEngine::Core
{
	enum class DirType;

	class ILoader
	{
	public:
		ILoader() = default;
		virtual ~ILoader() = default;

	public:
		virtual bool LoadFromFile(const std::string& filePath) = 0;
		virtual bool LoadFromNode(const pugi::xml_node& node) = 0;

		virtual std::string GetFilePath() const = 0;
		virtual DirType GetDirType() const = 0;
	};
}

#endif // _INTERFACE_LOADER_HEADER_
