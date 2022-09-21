#ifndef _META_ENUM_MEMBER_HEADER_
#define _META_ENUM_MEMBER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Data/Meta/Members/IMetaMember.hpp>

#include <TinyEngine/Gui/GuiVisitor.hpp>
#include <TinyEngine/Data/Serialization/SerializationDefines.hpp>

#include <string>

namespace TinyEngine
{
	template<typename T>
	class MetaEnumMemberWrapper : public IMetaMember
	{
		static_assert(std::is_enum_v<T>, "This member wrapper only for enum class!");

	public:
		MetaEnumMemberWrapper(std::string_view name, std::string_view description, const MetaMemberFlag& flags, T& value);
		~MetaEnumMemberWrapper() = default;

	public:
		void LoadFromArchive(InputArchivePtr archive) override;
		void SaveToArchive(OutputArchivePtr archive) override;

		void AddGuiWidget(GuiWidgetContainerPtr container) override;

	private:
		T& _value;
	};

	template<typename T>
	MetaEnumMemberWrapper<T>::MetaEnumMemberWrapper(std::string_view name, std::string_view description, const MetaMemberFlag& flags, T& value)
		: _value(value)
		, IMetaMember(name, description, flags)
	{
	}

	template<typename T>
	void MetaEnumMemberWrapper<T>::LoadFromArchive(InputArchivePtr archive)
	{
		if (IsLoadable())
		{
			SerializationVisitor<T>::Load(archive, GetName(), &_value);
		}
	}

	template<typename T>
	void MetaEnumMemberWrapper<T>::SaveToArchive(OutputArchivePtr archive)
	{
		if (IsSaved())
		{
			SerializationVisitor<T>::Save(archive, GetName(), &_value);
		}
	}

	template<typename T>
	void MetaEnumMemberWrapper<T>::AddGuiWidget(GuiWidgetContainerPtr container)
	{
		if (IsEditable())
		{
			GuiVisitor<T>::AddWidget(container, GetName(), GetDescription(), &_value);
		}
	}
}

#endif // _META_ENUM_MEMBER_HEADER_
