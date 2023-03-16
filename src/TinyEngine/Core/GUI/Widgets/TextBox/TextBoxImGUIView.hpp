#ifndef _TEXT_BOX_IMGUI_VIEW_HEADER_
#define _TEXT_BOX_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/TextBox/ITextBoxView.hpp>

namespace TinyEngine
{
	class TextBoxImGUIView final : public ITextBoxView
	{
	public:
		TextBoxImGUIView() = default;
		~TextBoxImGUIView() = default;

	public:
		virtual void OnDraw() override;

		virtual void OnActive() override;
		virtual void OnDeactive() override;

		virtual void OnShow() override;
		virtual void OnHide() override;

	public:
		virtual void SetText(std::string_view text) override;

	private:
		std::string _text;
	};
}

#endif // _TEXT_BOX_IMGUI_VIEW_HEADER_
