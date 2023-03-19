#ifndef _MENU_BAR_HEADER_
#define _MENU_BAR_HEADER_

#include <TinyEngine/Core/GUI/Widget.hpp>
#include <TinyEngine/Core/GUI/Widgets/MenuBar/MenuBarItem.hpp>

namespace TinyEngine
{
	class MenuBar final : public Widget
	{
	public:
		MenuBar() = default;
		~MenuBar() = default;

	public:
		const MenuBarContainer& GetMenuContainer() const { return _menuContainer; }
		MenuBarContainer& GetRefMenuContainer() { return _menuContainer; }

	protected:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const;

	private:
		MenuBarContainer _menuContainer;
	};
}

#endif // _MENU_BAR_HEADER_
