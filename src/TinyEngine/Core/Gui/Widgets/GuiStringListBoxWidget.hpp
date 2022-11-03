#ifndef _GUI_STRING_LIST_BOX_WIDGET_HEADER_
#define _GUI_STRING_LIST_BOX_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Gui/GuiWidget.hpp>

#include <vector>
#include <string>
#include <functional>

namespace TinyEngine
{
	class GuiStringListBoxWidget final : public GuiWidget
	{
	public:
		using OnChanged = std::function<void(std::string_view)>;

	public:
		GuiStringListBoxWidget() = default;
		~GuiStringListBoxWidget() = default;

	public:
		static GuiStringListBoxWidgetSharedPtr Create(std::string_view name);

	public:
		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

		void AddItem(std::string_view item);

		void SetCurrentItem(int number) { _currentItem = number; }
		int GetCurrentItem() const { return _currentItem; }
		
		std::string GetCurrentItemString() const;
		int GetItemsCount() const { return _itemsCount; }
		int GetNumberFromString(std::string_view item) const;

		void SetOnChangedCallback(const OnChanged& callback) { _onChangedCallback = callback; }

	public:
		void Draw(float deltaTime) override;

	private:
		static inline const int MAX_ITEMS = 64;

	private:
		std::string _name;
		int _currentItem = 0;
		const char* _items[MAX_ITEMS] {};
		int _itemsCount = 0;
		OnChanged _onChangedCallback;
	};
}

#endif // _GUI_STRING_LIST_BOX_WIDGET_HEADER_
