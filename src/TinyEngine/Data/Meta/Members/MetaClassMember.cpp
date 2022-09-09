#include "MetaClassMember.hpp"

#include <TinyEngine/Data/Meta/Class/MetaClass.hpp>
#include <TinyEngine/Gui/GuiVisitor.hpp>
#include <TinyEngine/Data/Serialization/SerializationDefines.hpp>

namespace TinyEngine
{
	MetaClassMemberWrapper::MetaClassMemberWrapper(std::string_view name, std::string_view description, const MetaMemberFlag& flags, MetaClassPtr metaClass)
		: _metaClass(metaClass)
		, IMetaMember(name, description, flags)
	{
	}

	void MetaClassMemberWrapper::LoadFromArchive(InputArchivePtr archive)
	{
		if (IsLoadable())
		{
			SerializationVisitor<MetaClass>::Load(archive, GetName(), _metaClass);
		}
	}

	void MetaClassMemberWrapper::SaveToArchive(OutputArchivePtr archive)
	{
		if (IsSaved())
		{
			SerializationVisitor<MetaClass>::Save(archive, GetName(), _metaClass);
		}
	}

	void MetaClassMemberWrapper::AddGuiWidget(GuiWidgetContainerPtr container, IRenderWindowSharedPtr window)
	{
		if (IsEditable())
		{
			GuiVisitor<MetaClass>::AddWidget(container, GetName(), GetDescription(), _metaClass);
		}
	}
}
