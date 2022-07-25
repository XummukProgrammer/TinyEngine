#ifndef _GUI_MENU_BAR_WIDGET_HEADER_
#define _GUI_MENU_BAR_WIDGET_HEADER_

#include <TinyEngine/Gui/GuiWidget.hpp>

#include <string>
#include <list>
#include <functional>

namespace TinyEngine
{
	class GuiMenuBarWidget final : public GuiWidget
	{
	public:
		using Ptr = std::shared_ptr<GuiMenuBarWidget>;

		struct Item
		{
			std::string name;
			std::function<void()> action;
		};

		struct Menu
		{
			std::string name;
			std::list<Item> items;
		};

	public:
		GuiMenuBarWidget() = default;
		~GuiMenuBarWidget() = default;

	public:
		static Ptr Create();

	public:
		void Draw(float deltaTime, IRenderWindowPtr renderWindowPtr) override;

	public:
		void AddMenu(const Menu& menu);

	private:
		std::list<Menu> _menus;
	};
}

#endif // _GUI_MENU_BAR_WIDGET_HEADER_
