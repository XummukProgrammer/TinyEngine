#include "TextBoxImGUIView.hpp"

#include "imgui.h"

namespace TinyEngine
{
    void TextBoxImGUIView::OnDraw()
    {
        ImGui::Text(_text.c_str());
    }

    void TextBoxImGUIView::SetText(std::string_view text)
    {
        _text = text;
    }
}
