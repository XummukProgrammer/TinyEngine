#include "GUI.hpp"

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Core/GUI/Widgets/Window/WindowImGUIView.hpp>
#include <TinyEngine/Core/GUI/Widgets/MenuBar/MenuBar.hpp>

namespace TinyEngine
{
    void GUI::Init()
    {
        _widgetsLayersContainers[WidgetsContainerType::ImGui] = std::make_unique<WidgetsLayersContainer>();

        for (auto& [type, container] : _widgetsLayersContainers)
        {
            container->Init();
        }

        _mainWindow = MakeWidget<ImGUIWindow>("MainWindow", Widget::ViewType::ImGUI, []()
        {
            return std::make_unique<MainWindowImGUIView>();
        });
        
        _menuBar = _mainWindow->MakeWidget<MenuBar>("MenuBar");
    }

    void GUI::Deinit()
    {
        for (auto& [type, container] : _widgetsLayersContainers)
        {
            container->Deinit();
        }
    }

    void GUI::Draw()
    {
        _widgetsLayersContainers[WidgetsContainerType::ImGui]->Draw();
    }

    Window* GUI::GetMainWindow() const
    {
        return _mainWindow;
    }

    MenuBar* GUI::GetMenuBar() const
    {
        return _menuBar;
    }

    GUI::WidgetsContainerType GUI::ViewToContainerType(Widget::ViewType widgetType)
    {
        switch (widgetType)
        {
        case TinyEngine::Widget::ViewType::ImGUI:
            return WidgetsContainerType::ImGui;
        default:
            break;
        }

        return WidgetsContainerType::ImGui;
    }

    WidgetsLayersContainer* GUI::GetContainerByViewType(Widget::ViewType viewType) const
    {
        return _widgetsLayersContainers.at(ViewToContainerType(viewType)).get();
    }
}
