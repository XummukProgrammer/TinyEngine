#include "IMetaMember.hpp"

namespace TinyEngine
{
	MetaMemberData::MetaMemberData(std::string_view name, std::string_view description)
		: _name(name)
		, _description(description)
	{
	}

	IMetaMember::IMetaMember(std::string_view name, std::string_view description)
		: MetaMemberData(name, description)
	{
	}
}
