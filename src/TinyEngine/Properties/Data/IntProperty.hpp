#ifndef _INT_PROPERTY_HEADER_
#define _INT_PROPERTY_HEADER_

#include <TinyEngine/Properties/PropertyData.hpp>

namespace TinyEngine::Properties::Data
{
	class IntProperty final : public PropertyData<int>
	{
	public:
		IntProperty() = default;
		~IntProperty() = default;
	};
}

#endif // _INT_PROPERTY_HEADER_
