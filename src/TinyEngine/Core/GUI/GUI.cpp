#include "GUI.hpp"

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Core/GUI/Widgets/Window/WindowImGUIView.hpp>
#include <TinyEngine/Core/GUI/Widgets/MenuBar/MenuBar.hpp>

namespace TinyEngine
{
    void GUI::Init()
    {
        auto mainWindow = MakeImGUIWidget<Window>("MainWindow", []()
        {
            return std::make_unique<MainWindowImGUIView>();
        });
        
        auto menuBar = MakeImGUIWidget<MenuBar>("MenuBar");
        mainWindow->GetRefWidgetsContainer().AddWidget(std::move(menuBar));

        AddWidget(std::move(mainWindow));

        _mainWindow = dynamic_cast<Window*>(GetImGUIWidgetsContainer().GetWidget("MainWindow"));
        _menuBar = dynamic_cast<MenuBar*>(_mainWindow->GetRefWidgetsContainer().GetWidget("MenuBar"));

    }

    void GUI::Deinit()
    {
    }

    void GUI::AddWidget(std::unique_ptr<Widget>&& widget)
    {
        switch (widget->GetViewType())
        {
        case Widget::ViewType::ImGUI:
            _imGUIWidgetsContainer.AddWidget(std::move(widget));
            break;

        default:
            break;
        }
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
