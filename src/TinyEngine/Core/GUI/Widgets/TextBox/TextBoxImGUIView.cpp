#include "TextBoxImGUIView.hpp"

#include "imgui.h"

namespace TinyEngine
{
    void TextBoxImGUIView::OnDraw()
    {
        ImGui::Text(_text.c_str());
    }

    void TextBoxImGUIView::OnActive()
    {
    }

    void TextBoxImGUIView::OnDeactive()
    {
    }

    void TextBoxImGUIView::OnShow()
    {
    }

    void TextBoxImGUIView::OnHide()
    {
    }

    void TextBoxImGUIView::SetText(std::string_view text)
    {
        _text = text;
    }
}
