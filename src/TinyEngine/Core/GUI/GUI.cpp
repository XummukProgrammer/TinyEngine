#include "GUI.hpp"

namespace TinyEngine
{
    void GUI::Draw()
    {
        for (auto& widget : _widgets)
        {
            widget->Draw();
        }
    }

    void GUI::AddWidget(std::unique_ptr<Widget>&& widget)
    {
        _widgets.push_back(std::move(widget));
        _widgets.back()->Init();
    }

    bool GUI::HasWidget(std::string_view name) const
    {
        return GetWidget(name) != nullptr;
    }

    Widget* GUI::GetWidget(std::string_view name) const
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
}
