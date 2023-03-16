#include "TextBox.hpp"

#include <TinyEngine/Core/GUI/Widgets/TextBox/TextBoxImGUIView.hpp>

namespace TinyEngine
{
    void TextBox::OnInit()
    {
        Widget::OnInit();
    }

    void TextBox::OnDeinit()
    {
        Widget::OnDeinit();
    }

    void TextBox::OnActive()
    {
    }

    void TextBox::OnDeactive()
    {
    }

    void TextBox::OnShow()
    {
    }

    void TextBox::OnHide()
    {
    }

    void TextBox::SetText(std::string_view text)
    {
        dynamic_cast<ITextBoxView*>(GetView())->SetText(text);
    }

    std::unique_ptr<IWidgetView> TextBox::MakeImGUIView() const
    {
        return std::make_unique<TextBoxImGUIView>();
    }
}
