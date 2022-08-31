#ifndef _META_DEFINES_HEADER_
#define _META_DEFINES_HEADER_

#include <TinyEngine/Data/Meta/Class/MetaClass.hpp>
#include <TinyEngine/Data/Meta/MetaVisitor.hpp>

namespace TinyEngine
{	
}

#define TINY_ENGINE_META_CLASS(className) \
	public: \
		const std::string GetName() const override { return #className; } \
		static std::string GetStaticName() { return #className; } \
	private:

#define TINY_ENGINE_META_CLASS_MEMBERS_BEGIN \
	public: \
		void OnLoad() override \
		{

#define TINY_ENGINE_META_CLASS_MEMBERS_END \
		} \
	private:

#define TINY_ENGINE_META_CLASS_MEMBER_WRAPPER(field, name, description) \
	TinyEngine::MetaVisitor<decltype(field)>::AddMemberWrapper(&GetMembers(), &field, name, description)

#endif // _META_DEFINES_HEADER_
