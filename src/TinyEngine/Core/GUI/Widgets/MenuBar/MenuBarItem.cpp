#include "MenuBarItem.hpp"

namespace TinyEngine
{
    void MenuBarData::ForEachItems(const ItemsForEachCallback& callback) const
    {
        for (const auto& item : _items)
        {
            callback(item.get());
        }
    }

    void MenuBarContainer::ForEachMenus(const MenusForEachCallback& callback) const
    {
        for (const auto& menu : _menus)
        {
            callback(menu.get());
        }
    }
}
