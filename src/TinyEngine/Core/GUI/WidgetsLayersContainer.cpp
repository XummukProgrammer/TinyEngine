#include "WidgetsLayersContainer.hpp"

namespace TinyEngine
{
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

    void WidgetsLayerContainer::AddWidget(std::unique_ptr<Widget>&& widget)
    {
        _widgets.push_back(std::move(widget));
        _widgets.back()->OnInit();
    }

    bool WidgetsLayerContainer::HasWidget(std::string_view name) const
    {
        return GetWidget(name) != nullptr;
    }

    Widget* WidgetsLayerContainer::GetWidget(std::string_view name) const
    {
        auto it = std::find_if(_widgets.begin(), _widgets.end(), [name](const std::unique_ptr<Widget>& widget)
            {
                return widget->GetName() == name;
            });

        if (it != _widgets.end())
        {
            return it->get();
        }

        return nullptr;
    }

    Widget* WidgetsLayerContainer::GetBackWidget() const
    {
        return _widgets.back().get();
    }

    void WidgetsLayersContainer::Init()
    {
        _layers[WidgetLayerType::MainWindow] = std::make_unique<WidgetsLayerContainer>();
        _layers[WidgetLayerType::PopupWindows] = std::make_unique<WidgetsLayerContainer>();
    }

    void WidgetsLayersContainer::Deinit()
    {
    }

    void WidgetsLayersContainer::Draw()
    {
        for (auto& [ type, layer ] : _layers)
        {
            layer->Draw();
        }
    }

    WidgetsLayerContainer* WidgetsLayersContainer::GetContainer(WidgetLayerType type) const
    {
        return _layers.at(type).get();
    }
}
