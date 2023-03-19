#ifndef _MENU_BAR_IMGUI_VIEW_HEADER_
#define _MENU_BAR_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/MenuBar/IMenuBarView.hpp>

namespace TinyEngine
{
	class MenuBarImGUIView final : public IMenuBarView
	{
	public:
		MenuBarImGUIView() = default;
		~MenuBarImGUIView() = default;

	public:
		virtual void OnDraw() override;
	};
}

#endif // _MENU_BAR_IMGUI_VIEW_HEADER_
