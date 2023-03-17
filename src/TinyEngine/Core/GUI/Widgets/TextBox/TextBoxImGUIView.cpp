#include "TextBoxImGUIView.hpp"

#include <TinyEngine/Core/GUI/Widget.hpp>

#include "imgui.h"

namespace TinyEngine
{
    void TextBoxImGUIView::OnDraw()
    {
        auto widget = GetWidget();

        if (widget->IsActive())
        {
            ImGui::Text(_text.c_str());
        }
        else
        {
            ImGui::TextDisabled(_text.c_str());
        }
    }

    void TextBoxImGUIView::SetText(std::string_view text)
    {
        _text = text;
    }
}
