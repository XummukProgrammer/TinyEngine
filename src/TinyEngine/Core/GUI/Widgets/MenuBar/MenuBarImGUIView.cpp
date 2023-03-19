#include "MenuBarImGUIView.hpp"

#include <TinyEngine/Core/GUI/Widgets/MenuBar/MenuBar.hpp>

#include "imgui.h"

namespace TinyEngine
{
    void MenuBarImGUIView::OnDraw()
    {
        if (ImGui::BeginMenuBar())
        {
            const auto& menuContainer = dynamic_cast<MenuBar*>(GetWidget())->GetMenuContainer();

            menuContainer.ForEachMenus([](MenuBarData* menu)
            {
                if (ImGui::BeginMenu(menu->GetTitle().c_str()))
                {
                    menu->ForEachItems([](MenuBarItem* item)
                    {
                        if (ImGui::MenuItem(item->GetTitle().c_str()))
                        {
                            item->OnAction();
                        }
                    });

                    ImGui::EndMenu();
                }
            });

            ImGui::EndMenuBar();
        }
    }
}
