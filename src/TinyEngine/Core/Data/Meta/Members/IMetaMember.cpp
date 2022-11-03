#include "IMetaMember.hpp"

#include <TinyEngine/Core/Constants.hpp>

namespace TinyEngine
{
	MetaMemberData::MetaMemberData(std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		: _name(name)
		, _description(description)
		, _flags(flags)
	{
	}

	IMetaMember::IMetaMember(std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		: MetaMemberData(name, description, flags)
	{
	}
}
