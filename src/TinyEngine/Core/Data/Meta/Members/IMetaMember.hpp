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
		virtual MetaMemberFlag GetFlags() const = 0;
		virtual bool IsSaved() const = 0;
		virtual bool IsLoadable() const = 0;
		virtual bool IsEditable() const = 0;

		virtual void SetName(std::string_view name) = 0;
		virtual void SetDescription(std::string_view description) = 0;

		virtual void SetSaveFlag() = 0;
		virtual void SetLoadFlag() = 0;
		virtual void SetEditorFlag() = 0;
		virtual void SetDefaultFlags() = 0;
	};
	
	template<typename T>
	class MetaMember final : public IMetaMember
	{
	public:
		MetaMember(T* value);
		~MetaMember() = default;

	public:
		void LoadFromArchive(InputArchivePtr archive) override;
		void SaveToArchive(OutputArchivePtr archive) override;

		void AddGuiWidget(GuiWidgetContainerPtr container) override;

	public:
		const std::string& GetName() const override { return _name; }
		const std::string& GetDescription() const override { return _description; }
		MetaMemberFlag GetFlags() const override { return static_cast<MetaMemberFlag>(_flags); }
		bool IsSaved() const override { return _flags & static_cast<int>(MetaMemberFlag::Save); }
		bool IsLoadable() const override { return _flags & static_cast<int>(MetaMemberFlag::Load); }
		bool IsEditable() const override { return _flags & static_cast<int>(MetaMemberFlag::Editor); }

		void SetName(std::string_view name) override { _name = name; }
		void SetDescription(std::string_view description) override { _description = description; }

		void SetSaveFlag() override { _flags |= static_cast<int>(MetaMemberFlag::Save); }
		void SetLoadFlag() override { _flags |= static_cast<int>(MetaMemberFlag::Load); }
		void SetEditorFlag() override { _flags |= static_cast<int>(MetaMemberFlag::Editor); }
		void SetDefaultFlags() override { _flags = static_cast<int>(MetaMemberFlag::Default); }

	private:
		std::string _name;
		std::string _description;
		int _flags;
		T* _value = nullptr;
	};

	template<typename T>
	MetaMember<T>::MetaMember(T* value)
		: _value(value)
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
