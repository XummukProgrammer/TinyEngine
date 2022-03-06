#include "BoolProperty.hpp"

namespace TinyEngine::Properties::Data
{
	std::string BoolProperty::ToString() const
	{
		return _value ? "true" : "false";
	}	
}
