#include "TextBoxImGUIView.hpp"

#include <TinyEngine/Core/GUI/Widget.hpp>

namespace TinyEngine
{
    void TextBoxImGUIView::OnDraw()
    {
        if (GetWidget()->IsActive())
        {
            if (_isMarker)
            {
                ImGui::BulletText(_text.c_str());
            }
            else
            {
                if (_colorOpt)
                {
                    ImGui::TextColored(_colorOpt.value(), _text.c_str());
                }
                else
                {
                    ImGui::Text(_text.c_str());
                }
            }
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

    void TextBoxImGUIView::SetColor(const raylib::Color& color)
    {
        _colorOpt = ImVec4(
            Normalize(static_cast<float>(color.r), 0, 255),
            Normalize(static_cast<float>(color.g), 0, 255),
            Normalize(static_cast<float>(color.b), 0, 255),
            Normalize(static_cast<float>(color.a), 0, 255)
        );
    }

    void TextBoxImGUIView::SetIsMarker(bool isMarker)
    {
        _isMarker = isMarker;
    }
}
