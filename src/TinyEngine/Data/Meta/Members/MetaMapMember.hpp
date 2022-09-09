#ifndef _META_MAP_MEMBER_HEADER_
#define _META_MAP_MEMBER_HEADER_

#include <TinyEngine/Data/Meta/Members/IMetaMember.hpp>
#include <TinyEngine/Gui/GuiVisitor.hpp>
#include <TinyEngine/Data/Serialization/SerializationDefines.hpp>

#include <map>

namespace TinyEngine
{
	template<typename K, typename V>
	class MetaMapMemberWrapper : public IMetaMember
	{
	public:
		MetaMapMemberWrapper(std::string_view name, std::string_view description, const MetaMemberFlag& flags, std::map<K, V>& values);
		~MetaMapMemberWrapper() = default;

	public:
		void LoadFromArchive(InputArchivePtr archive) override;
		void SaveToArchive(OutputArchivePtr archive) override;

		void AddGuiWidget(GuiWidgetContainerPtr container, IRenderWindowSharedPtr window) override;

	private:
		std::map<K, V>& _values;
	};

	template<typename K, typename V>
	MetaMapMemberWrapper<K, V>::MetaMapMemberWrapper(std::string_view name, std::string_view description, const MetaMemberFlag& flags, std::map<K, V>& values)
		: _values(values)
		, IMetaMember(name, description, flags)
	{
	}

	template<typename K, typename V>
	void MetaMapMemberWrapper<K, V>::LoadFromArchive(InputArchivePtr archive)
	{
		if (IsLoadable())
		{
			SerializationVisitor<std::map<K, V>>::Load(archive, GetName(), &_values);
		}
	}

	template<typename K, typename V>
	void MetaMapMemberWrapper<K, V>::SaveToArchive(OutputArchivePtr archive)
	{
		if (IsSaved())
		{
			SerializationVisitor<std::map<K, V>>::Save(archive, GetName(), &_values);
		}
	}

	template<typename K, typename V>
	void MetaMapMemberWrapper<K, V>::AddGuiWidget(GuiWidgetContainerPtr container, IRenderWindowSharedPtr window)
	{
		if (IsEditable())
		{
			GuiVisitor<std::map<K, V>>::AddWidget(container, GetName(), GetDescription(), &_values);
		}
	}
}

#endif // _META_MAP_MEMBER_HEADER_
