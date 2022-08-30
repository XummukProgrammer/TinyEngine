#ifndef _META_VISITOR_HEADER_
#define _META_VISITOR_HEADER_

#include <TinyEngine/Data/Meta/Members/MetaMembers.hpp>
#include <TinyEngine/Data/Meta/Members/MetaIntMember.hpp>

#include <string>

namespace TinyEngine
{
	template<typename T>
	class MetaVisitor
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, T* value, std::string_view name, std::string_view description) {}
	};

	template<>
	class MetaVisitor<int>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, int* value, std::string_view name, std::string_view description)
		{
			members->AddMember(std::make_shared<TinyEngine::MetaIntMemberWrapper>(name, description, *value));
		}
	};
}

#endif // _META_VISITOR_HEADER_
