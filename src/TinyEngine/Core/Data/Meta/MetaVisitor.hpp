#ifndef _META_VISITOR_HEADER_
#define _META_VISITOR_HEADER_

#include <TinyEngine/Core/Data/Meta/Class/MetaClass.hpp>
#include <TinyEngine/Core/Data/Meta/Members/MetaMembers.hpp>
#include <TinyEngine/Core/Data/Meta/Members/IMetaMember.hpp>

#include <string>
#include <vector>
#include <map>

namespace TinyEngine
{
	template<typename T>
	class MetaVisitor
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, T* value, std::string_view name, std::string_view description, const MetaMemberFlag& flags) 
		{
			if constexpr (std::is_base_of_v<MetaClass, T>)
			{
				members->AddMember(std::make_shared<MetaMember<MetaClass>>(name, description, flags, value));
			}
			else
			{
				members->AddMember(std::make_shared<MetaMember<T>>(name, description, flags, value));
			}
		}
	};
}

#endif // _META_VISITOR_HEADER_
