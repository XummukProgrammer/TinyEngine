#ifndef _INTERFACE_META_MEMBER_HEADER_
#define _INTERFACE_META_MEMBER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Constants.hpp>

#include <TinyEngine/Core/Gui/GuiVisitor.hpp>
#include <TinyEngine/Core/Data/Serialization/SerializationVisitor.hpp>

#include <string>

namespace TinyEngine
{
	class IMetaMember
	{
	public:
		IMetaMember() = default;
		virtual ~IMetaMember() = default;

	public:
		virtual void LoadFromArchive(InputArchivePtr archive) = 0;
		virtual void SaveToArchive(OutputArchivePtr archive) = 0;

		virtual void AddGuiWidget(GuiWidgetContainerPtr container) = 0;

	public:
		virtual const std::string& GetName() const = 0;
		virtual const std::string& GetDescription() const = 0;
		virtual const MetaMemberFlag& GetFlags() const = 0;
		virtual bool IsSaved() const = 0;
		virtual bool IsLoadable() const = 0;
		virtual bool IsEditable() const = 0;
	};
	
	template<typename T>
	class MetaMember final : public IMetaMember
	{
	public:
		MetaMember(std::string_view name, std::string_view description, const MetaMemberFlag& flags, T* value);
		~MetaMember() = default;

	public:
		void LoadFromArchive(InputArchivePtr archive) override;
		void SaveToArchive(OutputArchivePtr archive) override;

		void AddGuiWidget(GuiWidgetContainerPtr container) override;

	public:
		const std::string& GetName() const override { return _name; }
		const std::string& GetDescription() const override { return _description; }
		const MetaMemberFlag& GetFlags() const override { return _flags; }
		bool IsSaved() const override { return static_cast<int>(_flags) & static_cast<int>(MetaMemberFlag::Save); }
		bool IsLoadable() const override { return static_cast<int>(_flags) & static_cast<int>(MetaMemberFlag::Load); }
		bool IsEditable() const override { return static_cast<int>(_flags) & static_cast<int>(MetaMemberFlag::Editor); }

	private:
		std::string _name;
		std::string _description;
		MetaMemberFlag _flags;
		T* _value = nullptr;
	};

	template<typename T>
	MetaMember<T>::MetaMember(std::string_view name, std::string_view description, const MetaMemberFlag& flags, T* value)
		: _name(name)
		, _description(description)
		, _flags(flags)
		, _value(value)
	{
	}

	template<typename T>
	void MetaMember<T>::LoadFromArchive(InputArchivePtr archive)
	{
		if (IsLoadable() && _value)
		{
			SerializationVisitor<T>::Load(archive, GetName(), _value);
		}
	}

	template<typename T>
	void MetaMember<T>::SaveToArchive(OutputArchivePtr archive)
	{
		if (IsSaved() && _value)
		{
			SerializationVisitor<T>::Save(archive, GetName(), _value);
		}
	}

	template<typename T>
	void MetaMember<T>::AddGuiWidget(GuiWidgetContainerPtr container)
	{
		if (IsEditable())
		{
			GuiVisitor<T>::AddWidget(container, GetName(), GetDescription(), _value);
		}
	}
}

#endif // _INTERFACE_META_MEMBER_HEADER_
