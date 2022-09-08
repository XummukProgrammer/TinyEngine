#ifndef _META_DEFINES_HEADER_
#define _META_DEFINES_HEADER_

#include <TinyEngine/Data/Meta/Class/MetaClass.hpp>
#include <TinyEngine/Data/Meta/MetaVisitor.hpp>

namespace TinyEngine
{	
}

#define TINY_ENGINE_META_CLASS_BASE(className) \
	public: \
		const std::string GetClassName() const override { return #className; } \
		static std::string GetStaticClassName() { return #className; } \
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

#define TINY_ENGINE_META_CLASS_DELC_MEMBER(field, name, description) \
	TinyEngine::MetaVisitor<decltype(field)>::AddMemberWrapper(&GetMembers(false), &field, name, description)

#endif // _META_DEFINES_HEADER_
