#include "XmlUtils.hpp"

namespace TinyEngine::Utils
{
	bool TinyEngine::Utils::XmlUtils::GetAttributeBoolOrDefault(const pugi::xml_node& node, const std::string& id, bool default)
	{
		if (auto attr = node.attribute(id.c_str()))
		{
			return attr.as_bool();
		}

		return default;
	}

	int XmlUtils::GetAttributeIntOrDefault(const pugi::xml_node& node, const std::string& id, int default)
	{
		if (auto attr = node.attribute(id.c_str()))
		{
			return attr.as_int();
		}

		return default;
	}

	unsigned XmlUtils::GetAttributeUnsignedOrDefault(const pugi::xml_node& node, const std::string& id, unsigned default)
	{
		if (auto attr = node.attribute(id.c_str()))
		{
			return attr.as_uint();
		}

		return default;
	}

	float XmlUtils::GetAttributeFloatOrDefault(const pugi::xml_node& node, const std::string& id, float default)
	{
		if (auto attr = node.attribute(id.c_str()))
		{
			return attr.as_float();
		}

		return default;
	}

	std::string XmlUtils::GetAttributeStringOrDefault(const pugi::xml_node& node, const std::string& id, const std::string& default)
	{
		if (auto attr = node.attribute(id.c_str()))
		{
			return attr.as_string();
		}

		return default;
	}
}
