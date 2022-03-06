#ifndef _FLOAT_PROPERTY_HEADER_
#define _FLOAT_PROPERTY_HEADER_

#include <TinyEngine/Properties/IProperty.hpp>

namespace TinyEngine::Properties::Data
{
	class FloatProperty final : public IProperty
	{
	public:
		FloatProperty() = default;
		~FloatProperty() = default;

	public:
		void SetValue(float value) { _value = value; }
		float GetValue() const { return _value; }

		std::string ToString() const override;

	private:
		float _value = 0.f;
	};
}

#endif // _FLOAT_PROPERTY_HEADER_
