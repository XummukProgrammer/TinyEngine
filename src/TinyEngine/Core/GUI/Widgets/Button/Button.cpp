#include "Button.hpp"

#include <TinyEngine/Core/GUI/Widgets/Button/ButtonImGUIView.hpp>

namespace TinyEngine
{
    void Button::OnInit()
    {
        Widget::OnInit();

        dynamic_cast<IButtonView*>(GetView())->Init(this);
    }

    void Button::OnDeinit()
    {
        Widget::OnDeinit();
    }

    void Button::OnActive()
    {
    }

    void Button::OnDeactive()
    {
    }

    void Button::OnShow()
    {
    }

    void Button::OnHide()
    {
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
