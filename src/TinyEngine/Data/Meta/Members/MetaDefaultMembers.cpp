#include "MetaDefaultMembers.hpp"

#include <TinyEngine/Data/Serialization/SerializationDefines.hpp>

namespace TinyEngine
{
	TINY_ENGINE_DEFAULT_MEMBER_IMPL(MetaBoolMember, bool)
	TINY_ENGINE_DEFAULT_MEMBER_IMPL(MetaIntMember, int)
	TINY_ENGINE_DEFAULT_MEMBER_IMPL(MetaFloatMember, float)
	TINY_ENGINE_DEFAULT_MEMBER_IMPL(MetaStringMember, std::string)
}
