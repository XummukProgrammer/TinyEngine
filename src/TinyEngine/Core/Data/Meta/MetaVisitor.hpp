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
				MetaVisitor<MetaClass>::AddMemberWrapper(members, value, name, description, flags);
			}
			else if constexpr (std::is_enum_v<T>)
			{
				MetaVisitorUniqueImpl::EnumAddMemberWrapper(members, value, name, description, flags);
			}
		}
	};

	// TODO: Много повторяющегося кода, может сделать макросы?

	template<>
	class MetaVisitor<bool>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, bool* value, std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		{
			members->AddMember(std::make_shared<MetaMember<bool>>(name, description, flags, value));
		}
	};

	template<>
	class MetaVisitor<int>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, int* value, std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		{
			members->AddMember(std::make_shared<MetaMember<int>>(name, description, flags, value));
		}
	};

	template<>
	class MetaVisitor<float>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, float* value, std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		{
			members->AddMember(std::make_shared<MetaMember<float>>(name, description, flags, value));
		}
	};
	
	template<>
	class MetaVisitor<std::string>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, std::string* value, std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		{
			members->AddMember(std::make_shared<MetaMember<std::string>>(name, description, flags, value));
		}
	};

	template<typename T>
	class MetaVisitor<std::vector<T>>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, std::vector<T>* values, std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		{
			members->AddMember(std::make_shared<MetaMember<std::vector<T>>>(name, description, flags, values));
		}
	};

	template<typename K, typename V>
	class MetaVisitor<std::map<K, V>>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, std::map<K, V>* values, std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		{
			members->AddMember(std::make_shared<MetaMember<std::map<K, V>>>(name, description, flags, values));
		}
	};

	template<>
	class MetaVisitor<MetaClass>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, MetaClass* value, std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		{
			members->AddMember(std::make_shared<MetaMember<MetaClass>>(name, description, flags, value));
		}
	};

	template<typename T>
	class MetaVisitor<std::shared_ptr<T>>
	{
	public:
		static void AddMemberWrapper(MetaMembersPtr members, std::shared_ptr<T>* value, std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		{
			members->AddMember(std::make_shared<MetaMember<std::shared_ptr<T>>>(name, description, flags, value));
		}
	};

	class MetaVisitorUniqueImpl
	{
	public:
		template<typename T, typename = std::enable_if<std::is_enum_v<T>, bool>::type>
		static void EnumAddMemberWrapper(MetaMembersPtr members, T* value, std::string_view name, std::string_view description, const MetaMemberFlag& flags)
		{
			members->AddMember(std::make_shared<MetaMember<T>>(name, description, flags, value));
		}
	};
}

#endif // _META_VISITOR_HEADER_
