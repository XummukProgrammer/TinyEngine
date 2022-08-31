#ifndef _META_VISITOR_HEADER_
#define _META_VISITOR_HEADER_

#include <TinyEngine/Data/Meta/Members/MetaMembers.hpp>
#include <TinyEngine/Data/Meta/Members/MetaDefaultMembers.hpp>

#include <string>

namespace TinyEngine
{
	template<typename T>
	class MetaVisitor
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, T* value, std::string_view name, std::string_view description) {}
	};

	// TODO: Много повторяющегося кода, может сделать макросы?

	template<>
	class MetaVisitor<bool>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, bool* value, std::string_view name, std::string_view description)
		{
			members->AddMember(std::make_shared<TinyEngine::MetaBoolMemberWrapper>(name, description, *value));
		}
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

	template<>
	class MetaVisitor<float>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, float* value, std::string_view name, std::string_view description)
		{
			members->AddMember(std::make_shared<TinyEngine::MetaFloatMemberWrapper>(name, description, *value));
		}
	};
	
	template<>
	class MetaVisitor<std::string>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, std::string* value, std::string_view name, std::string_view description)
		{
			members->AddMember(std::make_shared<TinyEngine::MetaStringMemberWrapper>(name, description, *value));
		}
	};
}

#endif // _META_VISITOR_HEADER_
