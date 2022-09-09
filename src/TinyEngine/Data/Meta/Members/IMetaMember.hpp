#ifndef _INTERFACE_META_MEMBER_HEADER_
#define _INTERFACE_META_MEMBER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Constants.hpp>

#include <TinyEngine/Gui/GuiVisitor.hpp>

#include <string>

namespace TinyEngine
{
	class MetaMemberData
	{
	public:
		MetaMemberData(std::string_view name, std::string_view description, const MetaMemberFlag& flags);
		virtual ~MetaMemberData() = default;

	public:
		const std::string& GetName() const { return _name; }
		const std::string& GetDescription() const { return _description; }
		const MetaMemberFlag& GetFlags() const { return _flags; }
		bool IsSaved() const { return static_cast<int>(_flags) & static_cast<int>(MetaMemberFlag::Save); }
		bool IsLoadable() const { return static_cast<int>(_flags) & static_cast<int>(MetaMemberFlag::Load); }
		bool IsEditable() const { return static_cast<int>(_flags) & static_cast<int>(MetaMemberFlag::Editor); }

	private:
		std::string _name;
		std::string _description;
		MetaMemberFlag _flags;
	};

	class IMetaMember : public MetaMemberData
	{
	public:
		IMetaMember(std::string_view name, std::string_view description, const MetaMemberFlag& flags);
		virtual ~IMetaMember() = default;

	public:
		virtual void LoadFromArchive(InputArchivePtr archive) = 0;
		virtual void SaveToArchive(OutputArchivePtr archive) = 0;

		virtual void AddGuiWidget(GuiWidgetContainerPtr container, IRenderWindowSharedPtr window) = 0;
	};
}

#define TINY_ENGINE_DEFAULT_MEMBER_HEADER(className, type, defaultValue, setValueModifType) \
	class className ## Wrapper : public IMetaMember \
	{ \
	public: \
		className ## Wrapper(std::string_view name, std::string_view description, const MetaMemberFlag& flags, type& value); \
		virtual ~className ## Wrapper() = default; \
	\
	public: \
		void LoadFromArchive(InputArchivePtr archive) override; \
		void SaveToArchive(OutputArchivePtr archive) override; \
		\
		void AddGuiWidget(GuiWidgetContainerPtr container, IRenderWindowSharedPtr window) override; \
	\
	private: \
		type& _value; \
	}; \
	\
	class className final : public className ## Wrapper \
	{ \
	public: \
		className(std::string_view name, std::string_view description, const MetaMemberFlag& flags); \
		~className() = default; \
	\
	public: \
		void SetValue(type setValueModifType value) { _value = value; } \
		type GetValue() const { return _value; } \
	\
	private: \
		type _value = defaultValue; \
	};

#define TINY_ENGINE_DEFAULT_MEMBER_IMPL(className, type) \
	className ## Wrapper::className ## Wrapper(std::string_view name, std::string_view description, const MetaMemberFlag& flags, type& value) \
		: IMetaMember(name, description, flags) \
		, _value(value) \
	{ \
	} \
	\
	void className ## Wrapper::LoadFromArchive(InputArchivePtr archive) \
	{ \
		if (IsLoadable()) \
		{ \
			SerializationVisitor<type>::Load(archive, GetName(), &_value); \
		} \
	} \
	\
	void className ## Wrapper::SaveToArchive(OutputArchivePtr archive) \
	{ \
		if (IsSaved()) \
		{ \
			SerializationVisitor<type>::Save(archive, GetName(), &_value); \
		} \
	} \
	\
	void className ## Wrapper::AddGuiWidget(GuiWidgetContainerPtr container, IRenderWindowSharedPtr window) \
	{ \
		if (IsEditable()) \
		{ \
			GuiVisitor<type>::AddWidget(container, GetName(), GetDescription(), &_value); \
		} \
	} \
	\
	className::className(std::string_view name, std::string_view description, const MetaMemberFlag& flags) \
		: className ## Wrapper(name, description, flags, _value) \
	{ \
	}

#endif // _INTERFACE_META_MEMBER_HEADER_
