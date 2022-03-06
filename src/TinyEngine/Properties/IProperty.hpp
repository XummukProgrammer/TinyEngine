#ifndef _INTERFACE_PROPERTY_HEADER_
#define _INTERFACE_PROPERTY_HEADER_

#include <string>

namespace TinyEngine::Properties
{
	class IProperty
	{
	public:
		IProperty() = default;
		virtual ~IProperty() = default;

	public:
		virtual std::string ToString() const = 0;
	};
}

#endif // _INTERFACE_PROPERTY_HEADER_
