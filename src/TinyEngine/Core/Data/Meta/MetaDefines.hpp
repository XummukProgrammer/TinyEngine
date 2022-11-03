#ifndef _META_DEFINES_HEADER_
#define _META_DEFINES_HEADER_

#include <TinyEngine/Core/Data/Meta/Class/MetaClass.hpp>
#include <TinyEngine/Core/Data/Meta/MetaVisitor.hpp>

namespace TinyEngine
{	
}

#define TINY_ENGINE_META_CLASS_BASE(className) \
	public: \
		const std::string GetClassName() const override { return GetStaticClassName(); } \
		static std::string GetStaticClassName() { return #className; } \
		TinyEngine::MetaClassSharedPtr CreateSharedPtr() const override { return CreateStaticSharedPtr(); } \
		static TinyEngine::MetaClassSharedPtr CreateStaticSharedPtr() \
		{ \
			if constexpr (!std::is_abstract_v<className>) \
			{ \
				return std::dynamic_pointer_cast<MetaClass>(std::make_shared<className>()); \
			} \
			return nullptr; \
		} \
	private:

#define TINY_ENGINE_META_CLASS_BEGIN(className) \
	TINY_ENGINE_META_CLASS_BASE(className) \
	protected: \
		void OnLoad() override \
		{

#define TINY_ENGINE_META_CLASS_DERIVED_BEGIN(className, parentName) \
	TINY_ENGINE_META_CLASS_BEGIN(className) \
			parentName::OnLoad();

#define TINY_ENGINE_META_CLASS_END \
		} \
	private:

#define TINY_ENGINE_META_CLASS_DELC_MEMBER(field, name, description, flags) \
	TinyEngine::MetaVisitor<decltype(field)>::AddMemberWrapper(&GetMembers(false), &field, name, description, flags)

#define TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(field, name, description) \
	TinyEngine::MetaVisitor<decltype(field)>::AddMemberWrapper(&GetMembers(false), &field, name, description, TinyEngine::MetaMemberFlag::Default)

#endif // _META_DEFINES_HEADER_
