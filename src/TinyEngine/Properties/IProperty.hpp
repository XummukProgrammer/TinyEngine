#ifndef _INTERFACE_PROPERTY_HEADER_
#define _INTERFACE_PROPERTY_HEADER_

#include <TinyEngine/Core/Factory.hpp>

#include <pugixml.hpp>

#include <string>

namespace TinyEngine::Properties
{
	class IProperty : public Core::IFactory
	{
	public:
		IProperty() = default;
		virtual ~IProperty() = default;

	public:
		virtual std::string ToString() const = 0;
		virtual std::string GetType() const = 0;

		virtual void SaveToFile(pugi::xml_node& node) = 0;
		virtual void LoadFromFile(pugi::xml_node& node) = 0;
	};
}

#endif // _INTERFACE_PROPERTY_HEADER_
