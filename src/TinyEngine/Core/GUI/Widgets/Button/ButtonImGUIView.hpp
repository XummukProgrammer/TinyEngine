#ifndef _BUTTON_IMGUI_VIEW_HEADER_
#define _BUTTON_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Button/IButtonView.hpp>

namespace TinyEngine
{
	class ButtonImGUIView final : public IButtonView
	{
	public:
		ButtonImGUIView() = default;
		~ButtonImGUIView() = default;

	public:
		virtual void OnDraw() override;
	};
}

#endif // _BUTTON_IMGUI_VIEW_HEADER_
