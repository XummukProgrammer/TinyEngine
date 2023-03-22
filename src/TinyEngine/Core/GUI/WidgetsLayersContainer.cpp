#include "WidgetsLayersContainer.hpp"

namespace TinyEngine
{
    void WidgetsLayerContainer::Init()
    {
    }

    void WidgetsLayerContainer::Deinit()
    {
    }

    void WidgetsLayerContainer::Draw()
    {
        for (auto& widget : _widgets)
        {
            if (widget->IsVisible())
            {
                widget->OnDraw();
            }
        }
    }

    bool WidgetsLayerContainer::HasWidget(std::string_view name) const
    {
        return GetWidget<Widget>(name) != nullptr;
    }
}
