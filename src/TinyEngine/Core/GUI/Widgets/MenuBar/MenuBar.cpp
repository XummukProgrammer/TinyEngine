#include "MenuBar.hpp"

#include <TinyEngine/Core/GUI/Widgets/MenuBar/MenuBarImGUIView.hpp>

namespace TinyEngine
{
    std::unique_ptr<IWidgetView> MenuBar::MakeImGUIView() const
    {
        return std::make_unique<MenuBarImGUIView>();
    }
}
