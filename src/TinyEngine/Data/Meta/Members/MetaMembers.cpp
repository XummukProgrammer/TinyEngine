#include "MetaMembers.hpp"

#include <TinyEngine/Data/Meta/Members/IMetaMember.hpp>

namespace TinyEngine
{
	void MetaMembers::AddMember(IMetaMemberSharedPtr property)
	{
		_members[property->GetName()] = property;
	}

	IMetaMemberSharedPtr MetaMembers::GetMember(std::string_view id) const
	{
		auto it = _members.find(std::string{id});
		if (it != _members.end())
		{
			return it->second;
		}
		return nullptr;
	}

	void MetaMembers::ForEach(const OnForEach& callback) const
	{
		if (!callback)
		{
			return;
		}

		for (const auto& [ id, property ] : _members)
		{
			callback(id, property);
		}
	}

	void MetaMembers::LoadFromArchive(InputArchivePtr archive)
	{
		ForEach([archive](std::string_view id, IMetaMemberSharedPtr property)
		{
			property->LoadFromArchive(archive);
		});
	}

	void MetaMembers::SaveToArchive(OutputArchivePtr archive)
	{
		ForEach([archive](std::string_view id, IMetaMemberSharedPtr property)
		{
			property->SaveToArchive(archive);
		});
	}
}
