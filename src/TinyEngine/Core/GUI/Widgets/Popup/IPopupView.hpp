#ifndef _I_POPUP_IMGUI_VIEW_HEADER_
#define _I_POPUP_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Window/IWindowView.hpp>

namespace TinyEngine
{
	class IPopupView : public IWindowView
	{
	public:
		IPopupView() = default;
		virtual ~IPopupView() = default;
	};
}

#endif // _I_POPUP_IMGUI_VIEW_HEADER_
