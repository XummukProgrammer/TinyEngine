#include "WidgetView.hpp"

#include <TinyEngine/Core/GUI/Widget.hpp>

namespace TinyEngine
{
    void IWidgetView::SetWidget(Widget* widget)
    {
        _widget = widget;
    }

    Widget* IWidgetView::GetWidget() const
    {
        return _widget;
    }
}
