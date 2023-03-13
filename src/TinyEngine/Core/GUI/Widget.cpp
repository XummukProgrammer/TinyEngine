#include "Widget.hpp"

namespace TinyEngine
{
    void Widget::Draw()
    {
        _view->OnDraw();
    }

    void Widget::SetView(std::unique_ptr<IWidgetView>&& view)
    {
        _view = std::move(view);
    }
}
