#ifndef _POPUP_IMGUI_VIEW_HEADER_
#define _POPUP_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Popup/IPopupView.hpp>

namespace TinyEngine
{
	class PopupImGUIView final : public IPopupView
	{
	public:
		PopupImGUIView() = default;
		~PopupImGUIView() = default;

	public:
		virtual bool TryBegin() override;
		virtual void End() override;

		virtual void OnDraw() override {}
	};
}

#endif // _POPUP_IMGUI_VIEW_HEADER_
