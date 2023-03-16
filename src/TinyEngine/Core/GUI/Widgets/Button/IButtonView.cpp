#include "IButtonView.hpp"

namespace TinyEngine
{
    void IButtonView::Init(Button* button)
    {
        _button = button;
    }

    void IButtonView::OnPressed()
    {
        _button->OnPressed();
    }
}
