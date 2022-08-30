﻿#ifndef _META_CLASS_HEADER_
#define _META_CLASS_HEADER_

#include <TinyEngine/Data/Meta/Members/MetaMembers.hpp>

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

#endif // _META_CLASS_HEADER_
