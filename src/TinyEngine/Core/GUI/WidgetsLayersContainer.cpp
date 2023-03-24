#include "WidgetsLayersContainer.hpp"

namespace TinyEngine
{
    void WidgetsLayerContainer::Init()
    {
    }

    void WidgetsLayerContainer::Deinit()
    {
    }

    void WidgetsLayerContainer::Draw(const DrawCallback& onDrawCallback)
    {
        int index = 0;
        const int size = static_cast<int>(_widgets.size());

        for (auto& widget : _widgets)
        {
            if (widget->IsVisible())
            {
                widget->OnDraw();

                if (onDrawCallback)
                {
                    const bool isLastElement = index == size;
                    onDrawCallback(widget.get(), isLastElement);
                }
            }

            ++index;
        }
    }

    bool WidgetsLayerContainer::HasWidget(std::string_view name) const
    {
        return GetWidget<Widget>(name) != nullptr;
    }
}
