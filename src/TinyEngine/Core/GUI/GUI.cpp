#include "GUI.hpp"

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Core/GUI/Widgets/Window/WindowImGUIView.hpp>
#include <TinyEngine/Core/GUI/Widgets/MenuBar/MenuBar.hpp>

#include "imgui.h"
#include "rlImGui.h"

namespace TinyEngine
{
    void GUI::Init()
    {
        rlImGuiSetup(true);

        auto& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        _widgetsLayersContainers[WidgetsContainerType::ImGUIWidgets] = std::make_unique<WidgetsLayerContainer>();
        _widgetsLayersContainers[WidgetsContainerType::ImGUIPopups] = std::make_unique<WidgetsLayerContainer>();

        for (auto& [type, container] : _widgetsLayersContainers)
        {
            container->Init();
        }

        _mainImGUIWindow = MakeWidget<MainImGUIWindow>("MainWindow", Widget::ViewType::ImGUI);
        _imGUIMenuBar = _mainImGUIWindow->MakeWidget<MenuBar>("MenuBar");
    }

    void GUI::Deinit()
    {
        for (auto& [type, container] : _widgetsLayersContainers)
        {
            container->Deinit();
        }

        rlImGuiShutdown();
    }

    void GUI::Draw()
    {
        rlImGuiBegin();

        for (auto& [type, container] : _widgetsLayersContainers)
        {
            container->Draw();
        }

        TryOpenPopup();

        rlImGuiEnd();
    }

    Window* GUI::GetMainImGUIWindow() const
    {
        return _mainImGUIWindow;
    }

    MenuBar* GUI::GetImGUIMenuBar() const
    {
        return _imGUIMenuBar;
    }

    void GUI::SetImGUIOpenPopup(std::string_view widgetName)
    {
        _imGUIOpenPopup = widgetName;
    }

    WidgetsLayerContainer* GUI::GetContainer(Widget::ViewType viewType, WidgetsContainerAction action) const
    {
        WidgetsContainerType containerType{};

        switch (action)
        {
        case TinyEngine::GUI::WidgetsContainerAction::Widgets:
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
            break;
        case TinyEngine::GUI::WidgetsContainerAction::Popups:
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
            break;
        default:
            break;
        }
        
        return _widgetsLayersContainers.at(containerType).get();
    }

    void GUI::TryOpenPopup()
    {
        if (!_imGUIOpenPopup.empty())
        {
            ImGui::OpenPopup(_imGUIOpenPopup.c_str());
            _imGUIOpenPopup.clear();
        }
    }
}
