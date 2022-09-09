#ifndef _META_VECTOR_MEMBER_HEADER_
#define _META_VECTOR_MEMBER_HEADER_

#include <TinyEngine/Data/Meta/Members/IMetaMember.hpp>
#include <TinyEngine/Gui/GuiVisitor.hpp>
#include <TinyEngine/Data/Serialization/SerializationDefines.hpp>

#include <vector>

namespace TinyEngine
{
	template<typename T>
	class MetaVectorMemberWrapper : public IMetaMember
	{
	public:
		MetaVectorMemberWrapper(std::string_view name, std::string_view description, const MetaMemberFlag& flags, std::vector<T>& values);
		~MetaVectorMemberWrapper() = default;

	public:
		void LoadFromArchive(InputArchivePtr archive) override;
		void SaveToArchive(OutputArchivePtr archive) override;

		void AddGuiWidget(GuiWidgetContainerPtr container, IRenderWindowSharedPtr window) override;

	private:
		std::vector<T>& _values;
	};

	template<typename T>
	MetaVectorMemberWrapper<T>::MetaVectorMemberWrapper(std::string_view name, std::string_view description, const MetaMemberFlag& flags, std::vector<T>& values)
		: _values(values)
		, IMetaMember(name, description, flags)
	{
	}

	template<typename T>
	void MetaVectorMemberWrapper<T>::LoadFromArchive(InputArchivePtr archive)
	{
		if (IsLoadable())
		{
			SerializationVisitor<std::vector<T>>::Load(archive, GetName(), &_values);
		}
	}

	template<typename T>
	void MetaVectorMemberWrapper<T>::SaveToArchive(OutputArchivePtr archive)
	{
		if (IsSaved())
		{
			SerializationVisitor<std::vector<T>>::Save(archive, GetName(), &_values);
		}
	}

	template<typename T>
	void MetaVectorMemberWrapper<T>::AddGuiWidget(GuiWidgetContainerPtr container, IRenderWindowSharedPtr window)
	{
		if (IsEditable())
		{
			GuiVisitor<std::vector<T>>::AddWidget(container, GetName(), GetDescription(), &_values);
		}
	}
}

#endif // _META_VECTOR_MEMBER_HEADER_
