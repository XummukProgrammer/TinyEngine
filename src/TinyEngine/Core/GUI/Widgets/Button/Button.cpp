#include "Button.hpp"

#include <TinyEngine/Core/GUI/Widgets/Button/ButtonImGUIView.hpp>

namespace TinyEngine
{
    void Button::Init()
    {
        Widget::Init();

        dynamic_cast<IButtonView*>(GetView())->Init(this);
    }

    void Button::Deinit()
    {
        Widget::Deinit();
    }

    void Button::OnPressed()
    {
        _onPressedSignal.Emit();
    }

    void Button::SetText(std::string_view text)
    {
        dynamic_cast<IButtonView*>(GetView())->SetText(text);
    }

    std::unique_ptr<IWidgetView> Button::MakeImGUIView() const
    {
        return std::make_unique<ButtonImGUIView>();
    }
}
