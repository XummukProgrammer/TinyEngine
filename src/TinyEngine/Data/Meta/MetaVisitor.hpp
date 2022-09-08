#ifndef _META_VISITOR_HEADER_
#define _META_VISITOR_HEADER_

#include <TinyEngine/Data/Meta/Class/MetaClass.hpp>
#include <TinyEngine/Data/Meta/Members/MetaMembers.hpp>
#include <TinyEngine/Data/Meta/Members/MetaDefaultMembers.hpp>
#include <TinyEngine/Data/Meta/Members/MetaVectorMember.hpp>
#include <TinyEngine/Data/Meta/Members/MetaMapMember.hpp>
#include <TinyEngine/Data/Meta/Members/MetaClassMember.hpp>
#include <TinyEngine/Data/Meta/Members/MetaSharedPtrMember.hpp>

#include <string>
#include <vector>
#include <map>

namespace TinyEngine
{
	template<typename T>
	class MetaVisitor
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, T* value, std::string_view name, std::string_view description) 
		{
			if (std::is_base_of_v<MetaClass, T>)
			{
				MetaVisitor<MetaClass>::AddMemberWrapper(members, value, name, description);
			}
		}
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

	template<typename T>
	class MetaVisitor<std::vector<T>>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, std::vector<T>* values, std::string_view name, std::string_view description)
		{
			members->AddMember(std::make_shared<TinyEngine::MetaVectorMemberWrapper<T>>(name, description, *values));
		}
	};

	template<typename K, typename V>
	class MetaVisitor<std::map<K, V>>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, std::map<K, V>* values, std::string_view name, std::string_view description)
		{
			members->AddMember(std::make_shared<TinyEngine::MetaMapMemberWrapper<K, V>>(name, description, *values));
		}
	};

	template<>
	class MetaVisitor<MetaClass>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, MetaClass* value, std::string_view name, std::string_view description)
		{
			members->AddMember(std::make_shared<TinyEngine::MetaClassMemberWrapper>(name, description, value));
		}
	};

	template<typename T>
	class MetaVisitor<std::shared_ptr<T>>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, std::shared_ptr<T>* value, std::string_view name, std::string_view description)
		{
			members->AddMember(std::make_shared<TinyEngine::MetaSharedPtrMember<T>>(name, description, *value));
		}
	};
}

#endif // _META_VISITOR_HEADER_
