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

    int GuiStringListBoxWidget::GetNumberFromString(std::string_view item) const
    {
        const auto& data = item.data();
        int number = 0;
        for (; number < _itemsCount; ++number)
        {
            if (strcmp(_items[number], data) == 0)
            {
                break;
            }
        }
        return number;
    }

    void GuiStringListBoxWidget::Draw(float deltaTime)
    {
        GuiWidget::Draw(deltaTime);

        if (ImGui::Combo(_name.c_str(), &_currentItem, _items, _itemsCount) && _onChangedCallback)
        {
            _onChangedCallback(GetCurrentItemString());
        }
    }
}
