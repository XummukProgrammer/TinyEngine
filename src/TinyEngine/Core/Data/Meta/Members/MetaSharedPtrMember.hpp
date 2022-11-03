#ifndef _META_SHARED_PTR_MEMBER_HEADER_
#define _META_SHARED_PTR_MEMBER_HEADER_

#include <TinyEngine/Core/Data/Meta/Members/IMetaMember.hpp>
#include <TinyEngine/Core/Gui/GuiVisitor.hpp>
#include <TinyEngine/Core/Data/Serialization/SerializationDefines.hpp>

#include <memory>

namespace TinyEngine
{
	template<typename T>
	class MetaSharedPtrMember : public IMetaMember
	{
	public:
		MetaSharedPtrMember(std::string_view name, std::string_view description, const MetaMemberFlag& flags, std::shared_ptr<T>& value);
		~MetaSharedPtrMember() = default;

	public:
		void LoadFromArchive(InputArchivePtr archive) override;
		void SaveToArchive(OutputArchivePtr archive) override;

		void AddGuiWidget(GuiWidgetContainerPtr container) override;

	private:
		std::shared_ptr<T>& _value;
	};

	template<typename T>
	MetaSharedPtrMember<T>::MetaSharedPtrMember(std::string_view name, std::string_view description, const MetaMemberFlag& flags, std::shared_ptr<T>& value)
		: _value(value)
		, IMetaMember(name, description, flags)
	{
	}

	template<typename T>
	void MetaSharedPtrMember<T>::LoadFromArchive(InputArchivePtr archive)
	{
		if (IsLoadable())
		{
			SerializationVisitor<std::shared_ptr<T>>::Load(archive, GetName(), &_value);
		}
	}

	template<typename T>
	void MetaSharedPtrMember<T>::SaveToArchive(OutputArchivePtr archive)
	{
		if (IsSaved())
		{
			SerializationVisitor<std::shared_ptr<T>>::Save(archive, GetName(), &_value);
		}
	}

	template<typename T>
	void MetaSharedPtrMember<T>::AddGuiWidget(GuiWidgetContainerPtr container)
	{
		if (IsEditable())
		{
			GuiVisitor<std::shared_ptr<T>>::AddWidget(container, GetName(), GetDescription(), &_value);
		}
	}
}

#endif // _META_SHARED_PTR_MEMBER_HEADER_
