#ifndef _META_DEFINES_HEADER_
#define _META_DEFINES_HEADER_

#include <TinyEngine/Core/Data/Meta/Class/MetaClass.hpp>
#include <TinyEngine/Core/Data/Meta/MetaVisitor.hpp>

namespace TinyEngine
{	
}

#define TINY_ENGINE_META_CLASS_BASE(className, strClassName) \
	public: \
		const std::string GetClassName() const override { return GetStaticClassName(); } \
		static std::string GetStaticClassName() { return strClassName; } \
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

#define TINY_ENGINE_META_CLASS_BASE_BEGIN(className, strClassName) \
	TINY_ENGINE_META_CLASS_BASE(className, strClassName) \
	protected: \
		void OnLoad() override \
		{

#define TINY_ENGINE_META_CLASS_BEGIN(className) \
	TINY_ENGINE_META_CLASS_BASE_BEGIN(className, #className)

#define TINY_ENGINE_META_CLASS_BASE_DERIVED_BEGIN(className, parentName, strClassName) \
	TINY_ENGINE_META_CLASS_BASE_BEGIN(className, strClassName) \
			parentName::OnLoad();

#define TINY_ENGINE_META_CLASS_DERIVED_BEGIN(className, parentName) \
	TINY_ENGINE_META_CLASS_BASE_DERIVED_BEGIN(className, parentName, #className)

#define TINY_ENGINE_META_CLASS_END \
		} \
	private:

#define TINY_ENGINE_META_CLASS_DELC_MEMBER(field, ...) \
	TinyEngine::MetaVisitor<decltype(field)>::AddMemberWrapper(&GetMembers(false), &field, { __VA_ARGS__ })

#define TINY_ENGINE_META_CLASS_MEMBER_NAME(name) std::make_shared<TinyEngine::MetaMemberNameInitializer>(name)
#define TINY_ENGINE_META_CLASS_MEMBER_DESCRIPTION(description) std::make_shared<TinyEngine::MetaMemberDescriptionInitializer>(description)
#define TINY_ENGINE_META_CLASS_MEMBER_SAVE_FLAG() std::make_shared<TinyEngine::MetaMemberSaveFlagInitializer>()
#define TINY_ENGINE_META_CLASS_MEMBER_LOAD_FLAG() std::make_shared<TinyEngine::MetaMemberLoadFlagInitializer>()
#define TINY_ENGINE_META_CLASS_MEMBER_EDITOR_FLAG() std::make_shared<TinyEngine::MetaMemberEditorFlagInitializer>()
#define TINY_ENGINE_META_CLASS_MEMBER_DEFAULT_FLAGS() std::make_shared<TinyEngine::MetaMemberDefaultFlagsInitializer>()
#define TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(field, name, description) TINY_ENGINE_META_CLASS_DELC_MEMBER(field, TINY_ENGINE_META_CLASS_MEMBER_NAME(name), TINY_ENGINE_META_CLASS_MEMBER_DESCRIPTION(description), TINY_ENGINE_META_CLASS_MEMBER_DEFAULT_FLAGS())

#endif // _META_DEFINES_HEADER_
