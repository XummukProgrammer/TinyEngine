#include "GUI.hpp"

namespace TinyEngine
{
    void GUI::AddWidget(std::unique_ptr<Widget>&& widget)
    {
        switch (widget->GetViewType())
        {
        case Widget::ViewType::ImGUI:
            _imGUIWidgetsContainer.AddWidget(std::move(widget));
            break;

        default:
            break;
        }
    }
}
