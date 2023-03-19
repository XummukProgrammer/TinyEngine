#ifndef _MENU_BAR_ITEM_HEADER_
#define _MENU_BAR_ITEM_HEADER_

#include <TinyEngine/Core/Events/Signal.hpp>

#include <string>
#include <list>
#include <memory>
#include <functional>

namespace TinyEngine
{
	class MenuBarItem final
	{
	public:
		using ActionSignal = Signal<>;

	public:
		MenuBarItem() = default;
		~MenuBarItem() = default;

	public:
		void SetTitle(std::string_view title) { _title = title; }
		const std::string& GetTitle() const { return _title; }

		ActionSignal& GetOnActionSignal() { return _onActionSignal; }
		void OnAction() { _onActionSignal.Emit(); }

	private:
		std::string _title;
		ActionSignal _onActionSignal;
	};

	class MenuBarData final
	{
	public:
		using ItemPtr = std::unique_ptr<MenuBarItem>;
		using ItemsList = std::list<ItemPtr>;
		using ItemsForEachCallback = std::function<void(MenuBarItem*)>;

	public:
		MenuBarData() = default;
		~MenuBarData() = default;

	public:
		void SetTitle(std::string_view title) { _title = title; }
		const std::string& GetTitle() const { return _title; }

		void AddItem(ItemPtr&& item) { _items.push_back(std::move(item)); }
		void ForEachItems(const ItemsForEachCallback& callback) const;

	private:
		std::string _title;
		ItemsList _items;
	};

	class MenuBarContainer final
	{
	public:
		using MenuPtr = std::unique_ptr<MenuBarData>;
		using MenusList = std::list<MenuPtr>;
		using MenusForEachCallback = std::function<void(MenuBarData*)>;

	public:
		MenuBarContainer() = default;
		~MenuBarContainer() = default;

	public:
		void AddMenu(MenuPtr&& menu) { _menus.push_back(std::move(menu)); }
		void ForEachMenus(const MenusForEachCallback& callback) const;

	private:
		MenusList _menus;
	};
}

#endif // _MENU_BAR_ITEM_HEADER_
