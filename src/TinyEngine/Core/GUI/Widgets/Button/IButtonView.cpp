#include "IButtonView.hpp"

#include <TinyEngine/Core/GUI/Widgets/Button/Button.hpp>

namespace TinyEngine
{
    void IButtonView::OnPressed()
    {
        dynamic_cast<Button*>(GetWidget())->OnPressed();
    }
}
