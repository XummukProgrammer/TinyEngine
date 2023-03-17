#include "TextBox.hpp"

#include <TinyEngine/Core/GUI/Widgets/TextBox/TextBoxImGUIView.hpp>

namespace TinyEngine
{
    void TextBox::SetText(std::string_view text)
    {
        dynamic_cast<ITextBoxView*>(GetView())->SetText(text);
    }

    void TextBox::SetColor(const raylib::Color& color)
    {
        dynamic_cast<ITextBoxView*>(GetView())->SetColor(color);
    }

    void TextBox::SetIsMarker(bool isMarker)
    {
        dynamic_cast<ITextBoxView*>(GetView())->SetIsMarker(isMarker);
    }

    std::unique_ptr<IWidgetView> TextBox::MakeImGUIView() const
    {
        return std::make_unique<TextBoxImGUIView>();
    }
}
