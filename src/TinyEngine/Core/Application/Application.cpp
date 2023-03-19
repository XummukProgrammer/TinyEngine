#include "Application.hpp"

#include <TinyEngine/Core/Application/Project.hpp>
#include <TinyEngine/Core/GUI/GUI.hpp>

#include <TinyEngine/Core/GUI/Widgets/TextBox/TextBox.hpp>
#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Core/GUI/Widgets/SameLine/SameLine.hpp>
#include <TinyEngine/Core/GUI/Widgets/Button/Button.hpp>
#include <TinyEngine/Core/GUI/Widgets/MenuBar/MenuBar.hpp>

#include <fmt/format.h>
#include "rlImGui.h"

#include "imgui.h"

namespace TinyEngine
{
    Application Application::_singleton;

    bool isOpenTestModal = false;

    void Application::Load()
    {
        OnInit();
    }

    void Application::Create()
    {
        _window.Init(_context.GetScreenWidth(), _context.GetScreenHeight(), _context.GetWindowTitle());
        rlImGuiSetup(true);
        _context.GetGUI()->Init();

        auto& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ProjectFileCreateParams params;
        params.path = _context.GetFileSystem().BuildPath(FileSystem::Assets, L"project.xml");
        params.name = "TinyEngine";
        params.description = "Game Engine";
        params.author = "Xummuk97";
        params.version = "1.0.0.0 alpha";
        params.librariesPath = "libs.xml";
        _context.GetProject()->Create(params);

        auto window = _context.GetGUI()->MakeWidget<Window>("DebugWindow", Widget::ViewType::ImGUI);
        window->SetTitle("Main Window");

        {
            auto textBox = window->GetRefWidgetsContainer().MakeWidget<TextBox>("First", Widget::ViewType::ImGUI);
            textBox->SetText("First!");
            textBox->SetIsMarker(true);
        }
        {
            window->GetRefWidgetsContainer().MakeWidget<SameLine>("SameLine1", Widget::ViewType::ImGUI);
        }
        {
            auto textBox = window->GetRefWidgetsContainer().MakeWidget<TextBox>("Second", Widget::ViewType::ImGUI);
            textBox->SetText("Second!");
            textBox->SetActive(false);
        }
        {
            auto button = window->GetRefWidgetsContainer().MakeWidget<Button>("Button", Widget::ViewType::ImGUI);
            button->SetText("Open Modal");
            auto slot = button->GetOnPressedSignal().MakeSlot([]()
                {
                });
            button->GetOnPressedSignal().Connect(slot);
        }
        {
            auto menuBar = _context.GetGUI()->GetMenuBar();

            auto projectMenu = std::make_unique<MenuBarData>();
            projectMenu->SetTitle("Project");

            auto projectCloseAppItem = std::make_unique<MenuBarItem>();
            projectCloseAppItem->SetTitle("Close App");
            projectCloseAppItem->GetOnActionSignal().Connect(projectCloseAppItem->GetOnActionSignal().MakeSlot([]()
            {
                isOpenTestModal = true;
            }));

            projectMenu->AddItem(std::move(projectCloseAppItem));

            menuBar->GetRefMenuContainer().AddMenu(std::move(projectMenu));
        }
    }

    void Application::Run()
    {
        while (!_window.ShouldClose())
        {
            OnUpdate();

            _window.BeginDrawing();
            _window.ClearBackground(RAYWHITE);
            OnDraw();
            rlImGuiBegin();
            _context.GetGUI()->GetRefImGUIWidgetsContainer().Draw();
            if (isOpenTestModal)
            {
                ImGui::OpenPopup("Test Modal");
            }
            if (ImGui::BeginPopupModal("Test Modal", nullptr))
            {
                ImGui::Text("Test");
                ImGui::EndPopup();
            }
            rlImGuiEnd();
            _window.EndDrawing();
        }
    }

    void Application::Stop()
    {
        OnDeinit();
    }

    void Application::ChangeState(State state)
    {
        switch (state)
        {
        case State::NotInitialized:
            break;
        case State::ProjectLoaded:
            if (_state == State::NotInitialized)
            {
                OnProjectLoaded();
            }
            break;
        case State::Started:
            if (_state == State::ProjectLoaded)
            {
                OnStarted();
            }
            break;
        default:
            break;
        }

        _state = state;
    }

    void Application::OnInit()
    {
        _context.GetGUI()->Deinit();
        _context.GetRefFileSystem().Init();
        _context.GetProject()->Init();
    }

    void Application::OnDeinit()
    {
        _context.GetRefFileSystem().Deinit();
        _context.GetProject()->Deinit();

        rlImGuiShutdown();
    }

    void Application::OnUpdate()
    {
    }

    void Application::OnDraw()
    {
        _context.GetRootTransform()->Draw();
    }

    void Application::OnProjectLoaded()
    {
        const auto& projectFile = _context.GetProject()->GetProjectFile();
        _window.SetTitle(fmt::format("{}_{}", projectFile.GetName(), projectFile.GetVersion()));
    }

    void Application::OnStarted()
    {
    }

    void StartApp(int argc, char** argv)
    {
        const std::string applicationVersion = "1.0.0.0a";

        Context context;
        context.SetArgc(argc);
        context.SetArgv(argv);
        context.SetScreenWidth(800);
        context.SetScreenHeight(600);
        context.SetWindowTitle("TinyEngine");
        context.SetScalePixelCoef(50);
        context.SetIsDrawGizmos(true);

        auto& application = Application::GetSingleton();
        application.SetContext(context);

        application.Load();
        application.Create();

        application.Run();
        application.Stop();
    }
}
