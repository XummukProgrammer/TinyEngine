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

		virtual void OnActive() override;
		virtual void OnDeactive() override;

		virtual void OnShow() override;
		virtual void OnHide() override;
	};
}

#endif // _BUTTON_IMGUI_VIEW_HEADER_
