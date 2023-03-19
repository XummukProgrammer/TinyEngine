#ifndef _I_MENU_BAR_VIEW_HEADER_
#define _I_MENU_BAR_VIEW_HEADER_

#include <TinyEngine/Core/GUI/WidgetView.hpp>

namespace TinyEngine
{
	class IMenuBarView : public IWidgetView
	{
	public:
		IMenuBarView() = default;
		virtual ~IMenuBarView() = default;
	};
}

#endif // _I_MENU_BAR_VIEW_HEADER_
