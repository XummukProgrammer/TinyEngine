#include "GUI.hpp"

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Core/GUI/Widgets/Window/WindowImGUIView.hpp>
#include <TinyEngine/Core/GUI/Widgets/MenuBar/MenuBar.hpp>

namespace TinyEngine
{
    void GUI::Init()
    {
        _imGUIWidgetsLayersContainer.Init();

        _mainWindow = MakeWidget<Window>("MainWindow", Widget::ViewType::ImGUI, []()
        {
            return std::make_unique<MainWindowImGUIView>();
        });
        
        _menuBar = _mainWindow->GetRefWidgetsContainer().MakeWidget<MenuBar>("MenuBar", Widget::ViewType::ImGUI);
    }

    void GUI::Deinit()
    {
        _imGUIWidgetsLayersContainer.Deinit();
    }

    Window* GUI::GetMainWindow() const
    {
        return _mainWindow;
    }

    MenuBar* GUI::GetMenuBar() const
    {
        return _menuBar;
    }
}
