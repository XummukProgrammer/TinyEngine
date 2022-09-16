#include "GuiStringListBoxWidget.hpp"

namespace TinyEngine
{
    GuiStringListBoxWidgetSharedPtr GuiStringListBoxWidget::Create(std::string_view name)
    {
        auto widget = std::make_shared<GuiStringListBoxWidget>();
        widget->SetName(name);
        return widget;
    }

    void GuiStringListBoxWidget::AddItem(std::string_view item)
    {
        _items[_itemsCount] = item.data();
        ++_itemsCount;
    }

    std::string GuiStringListBoxWidget::GetCurrentItemString() const
    {
        return _items[_currentItem];
    }

    void GuiStringListBoxWidget::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
    {
        GuiWidget::Draw(deltaTime, renderWindowPtr);

        ImGui::Combo(_name.c_str(), &_currentItem, _items, _itemsCount);
    }
}
