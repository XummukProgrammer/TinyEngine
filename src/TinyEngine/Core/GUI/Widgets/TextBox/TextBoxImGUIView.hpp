#ifndef _TEXT_BOX_IMGUI_VIEW_HEADER_
#define _TEXT_BOX_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/TextBox/ITextBoxView.hpp>

#include "imgui.h"

#include <optional>

namespace TinyEngine
{
	class TextBoxImGUIView final : public ITextBoxView
	{
	public:
		TextBoxImGUIView() = default;
		~TextBoxImGUIView() = default;

	public:
		virtual void OnDraw() override;

	public:
		virtual void SetText(std::string_view text) override;
		virtual void SetColor(const raylib::Color& color) override;

	private:
		std::string _text;
		std::optional<ImVec4> _colorOpt;
	};
}

#endif // _TEXT_BOX_IMGUI_VIEW_HEADER_
