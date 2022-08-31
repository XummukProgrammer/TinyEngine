#include "MetaMembers.hpp"

#include <TinyEngine/Data/Meta/Members/IMetaMember.hpp>
#include <TinyEngine/Gui/GuiWidgetContainer.hpp>

namespace TinyEngine
{
	void MetaMembers::AddMember(IMetaMemberSharedPtr member)
	{
		_members[member->GetName()] = member;
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

		for (const auto& [ id, member ] : _members)
		{
			callback(id, member);
		}
	}

	void MetaMembers::LoadFromArchive(InputArchivePtr archive)
	{
		ForEach([archive](std::string_view id, IMetaMemberSharedPtr member)
		{
			member->LoadFromArchive(archive);
		});
	}

	void MetaMembers::SaveToArchive(OutputArchivePtr archive)
	{
		ForEach([archive](std::string_view id, IMetaMemberSharedPtr member)
		{
			member->SaveToArchive(archive);
		});
	}

	void MetaMembers::AddGuiWidgetsToContainer(GuiWidgetContainerPtr container)
	{
		ForEach([container](std::string_view id, IMetaMemberSharedPtr member)
		{
			// TODO: Передавать не Nullptr, а RenderWindow (Или вообще убрать передачу).
			member->AddGuiWidget(container, nullptr);
		});
	}
}
