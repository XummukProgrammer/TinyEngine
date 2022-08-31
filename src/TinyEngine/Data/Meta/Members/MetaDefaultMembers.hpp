#ifndef _META_DEFAULT_MEMBERS_HEADER_
#define _META_DEFAULT_MEMBERS_HEADER_

#include <TinyEngine/Data/Meta/Members/IMetaMember.hpp>

#include <string>

namespace TinyEngine
{
	TINY_ENGINE_DEFAULT_MEMBER_HEADER(MetaBoolMember, bool, false, const)
	TINY_ENGINE_DEFAULT_MEMBER_HEADER(MetaIntMember, int, 0, const)
	TINY_ENGINE_DEFAULT_MEMBER_HEADER(MetaFloatMember, float, 0.f, const)
	TINY_ENGINE_DEFAULT_MEMBER_HEADER(MetaStringMember, std::string, "", const&)
}

#endif // _META_DEFAULT_MEMBERS_HEADER_
