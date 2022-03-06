#ifndef _STRING_PROPERTY_HEADER_
#define _STRING_PROPERTY_HEADER_

#include <TinyEngine/Properties/IProperty.hpp>

#include <string>

namespace TinyEngine::Properties::Data
{
	class StringProperty final : public IProperty
	{
	public:
		StringProperty() = default;
		~StringProperty() = default;

	public:
		void SetValue(std::string_view value) { _value = value; }
		const std::string& GetValue() const { return _value; }

		std::string ToString() const override;

	private:
		std::string _value;
	};
}

#endif // _STRING_PROPERTY_HEADER_
