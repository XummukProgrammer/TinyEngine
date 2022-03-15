#ifndef _XML_UTILS_HEADER_
#define _XML_UTILS_HEADER_

#include <pugixml.hpp>

#include <string>

namespace TinyEngine::Utils
{
	class XmlUtils final
	{
	public:
		static bool GetAttributeBoolOrDefault(const pugi::xml_node& node, const std::string& id, bool default);
		static int GetAttributeIntOrDefault(const pugi::xml_node& node, const std::string& id, int default);
		static unsigned GetAttributeUnsignedOrDefault(const pugi::xml_node& node, const std::string& id, unsigned default);
		static float GetAttributeFloatOrDefault(const pugi::xml_node& node, const std::string& id, float default);
		static std::string GetAttributeStringOrDefault(const pugi::xml_node& node, const std::string& id, const std::string& default);
	};
}

#endif // _XML_UTILS_HEADER_
