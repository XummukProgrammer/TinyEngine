#ifndef _META_CLASS_HEADER_
#define _META_CLASS_HEADER_

#include <TinyEngine/Data/Meta/Members/MetaMembers.hpp>
#include <TinyEngine/Data/Meta/Members/MetaIntMember.hpp>

#include <string>

namespace TinyEngine
{
	class MetaClass
	{
	public:
		MetaClass() = default;
		virtual ~MetaClass() = default;

	public:
		virtual const std::string GetName() const = 0;
		static std::string GetStaticName() { return ""; }

		MetaMembers& GetMembers() { return _members; }
		const MetaMembers& GetConstMembers() const { return _members; }

		virtual void OnLoad() = 0;

	private:
		MetaMembers _members;
	};
}

#define META_CLASS(className) \
	const std::string GetName() const override { return #className; } \
	static std::string GetStaticName() { return #className; }

#define META_CLASS_MEMBERS_BEGIN \
	public: \
		void OnLoad() override \
		{

#define META_CLASS_MEMBERS_END \
		} \
	private:

#define META_CLASS_INT_MEMBER_WRAPPER(field, name, description) \
	GetMembers().AddMember(std::make_shared<TinyEngine::MetaIntMemberWrapper>(name, description, field))

#endif // _META_CLASS_HEADER_
