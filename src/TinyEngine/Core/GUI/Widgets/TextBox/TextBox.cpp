#include "TextBox.hpp"

#include <TinyEngine/Core/GUI/Widgets/TextBox/TextBoxImGUIView.hpp>

namespace TinyEngine
{
    void TextBox::Init()
    {
        Widget::Init();
    }

    void TextBox::Deinit()
    {
        Widget::Deinit();
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
