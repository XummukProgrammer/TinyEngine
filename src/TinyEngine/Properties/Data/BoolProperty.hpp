#ifndef _BOOL_PROPERTY_HEADER_
#define _BOOL_PROPERTY_HEADER_

#include <TinyEngine/Properties/IProperty.hpp>

namespace TinyEngine::Properties::Data
{
	class BoolProperty final : public IProperty
	{
	public:
		BoolProperty() = default;
		~BoolProperty() = default;

	public:
		void SetValue(bool value) { _value = value; }
		bool GetValue() const { return _value; }

	private:
		bool _value = false;
	};
}

#endif // _BOOL_PROPERTY_HEADER_
