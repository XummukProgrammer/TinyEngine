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
		static void AddMemberWrapper(MetaMembersPtr members, T* value, const MetaMembers::MemberInitializerList& initializerList) 
		{
			if constexpr (std::is_base_of_v<MetaClass, T>)
			{
				members->AddMember(std::make_shared<MetaMember<MetaClass>>(value), initializerList);
			}
			else
			{
				members->AddMember(std::make_shared<MetaMember<T>>(value), initializerList);
			}
		}
	};
}

#endif // _META_VISITOR_HEADER_
