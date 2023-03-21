#include "GUI.hpp"

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Core/GUI/Widgets/Window/WindowImGUIView.hpp>
#include <TinyEngine/Core/GUI/Widgets/MenuBar/MenuBar.hpp>

namespace TinyEngine
{
    void GUI::Init()
    {
        _widgetsLayersContainers[WidgetsContainerType::ImGUIWidgets] = std::make_unique<WidgetsLayersContainer>();
        _widgetsLayersContainers[WidgetsContainerType::ImGUIPopups] = std::make_unique<WidgetsLayersContainer>();

        for (auto& [type, container] : _widgetsLayersContainers)
        {
            container->Init();
        }

        // TODO: Убрать CustomMake, указывать вьюху в контроллере
        _mainImGUIWindow = MakeWidget<ImGUIWindow>("MainWindow", Widget::ViewType::ImGUI, []()
        {
            return std::make_unique<MainWindowImGUIView>();
        });
        
        _imGUIMenuBar = _mainImGUIWindow->MakeWidget<MenuBar>("MenuBar");
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
        for (auto& [type, container] : _widgetsLayersContainers)
        {
            container->Draw();
        }
    }

    Window* GUI::GetMainImGUIWindow() const
    {
        return _mainImGUIWindow;
    }

    MenuBar* GUI::GetImGUIMenuBar() const
    {
        return _imGUIMenuBar;
    }

    WidgetsLayersContainer* GUI::GetContainer(Widget::ViewType viewType, bool isWidgets) const
    {
        WidgetsContainerType containerType{};

        if (isWidgets)
        {
            switch (viewType)
            {
            case TinyEngine::Widget::ViewType::ImGUI:
                containerType = WidgetsContainerType::ImGUIWidgets;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (viewType)
            {
            case TinyEngine::Widget::ViewType::ImGUI:
                containerType = WidgetsContainerType::ImGUIPopups;
                break;
            default:
                break;
            }
        }
        
        return _widgetsLayersContainers.at(containerType).get();
    }
}
