#include "Widget.hpp"

namespace TinyEngine
{
    void Widget::Draw()
    {
        _view->OnDraw();
    }

    void Widget::MakeView(ViewType type)
    {
        switch (type)
        {
        case TinyEngine::Widget::ViewType::ImGUI:
            SetView(std::move(MakeImGUIView()));
            break;
        default:
            break;
        }

        _viewType = type;
    }

    void Widget::SetView(std::unique_ptr<IWidgetView>&& view)
    {
        _view = std::move(view);
    }
}
