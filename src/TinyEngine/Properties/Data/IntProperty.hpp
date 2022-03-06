﻿#ifndef _INT_PROPERTY_HEADER_
#define _INT_PROPERTY_HEADER_

#include <TinyEngine/Properties/IProperty.hpp>

namespace TinyEngine::Properties::Data
{
	class IntProperty final : public IProperty
	{
	public:
		IntProperty() = default;
		~IntProperty() = default;

	public:
		void SetValue(int value) { _value = value; }
		int GetValue() const { return _value; }

	private:
		int _value = 0;
	};
}

#endif // _INT_PROPERTY_HEADER_
