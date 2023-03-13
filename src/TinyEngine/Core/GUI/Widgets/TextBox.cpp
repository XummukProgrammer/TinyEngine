#include "TextBox.hpp"

#include <TinyEngine/Core/GUI/Widgets/Views/ImGUI/TextBoxImGUIView.hpp>

namespace TinyEngine
{
    void TextBox::Init()
    {
        Widget::Init();

        SetView(std::move(GetTextBoxView()));
    }

    void TextBox::Deinit()
    {
        Widget::Deinit();
    }

    void TextBox::SetText(std::string_view text)
    {
        dynamic_cast<ITextBoxView*>(GetView())->SetText(text);
    }

    std::unique_ptr<ITextBoxView> TextBox::GetTextBoxView() const
    {
        return std::make_unique<TextBoxImGUIView>();
    }
}
