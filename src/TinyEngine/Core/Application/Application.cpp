#include "Application.hpp"

#include <TinyEngine/Core/Application/Project.hpp>
#include <TinyEngine/Core/GUI/GUI.hpp>

#include <TinyEngine/Core/GUI/Widgets/TextBox/TextBox.hpp>
#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Core/GUI/Widgets/SameLine/SameLine.hpp>
#include <TinyEngine/Core/GUI/Widgets/Button/Button.hpp>

#include <fmt/format.h>
#include "rlImGui.h"

#include "imgui.h"

namespace TinyEngine
{
    Application Application::_singleton;

    void Application::Load()
    {
        OnInit();
    }

    void Application::Create()
    {
        _window.Init(_context.GetScreenWidth(), _context.GetScreenHeight(), _context.GetWindowTitle());
        rlImGuiSetup(true);

        ProjectFileCreateParams params;
        params.path = _context.GetFileSystem().BuildPath(FileSystem::Assets, L"project.xml");
        params.name = "TinyEngine";
        params.description = "Game Engine";
        params.author = "Xummuk97";
        params.version = "1.0.0.0 alpha";
        params.librariesPath = "libs.xml";
        _context.GetProject()->Create(params);

        auto window = GUI::MakeImGUIWidget<Window>("Window");
        window->SetTitle("Main Window");

        {
            auto textBox = GUI::MakeImGUIWidget<TextBox>("First");
            textBox->SetText("First!");
            window->GetRefWidgetsContainer().AddWidget(std::move(textBox));
        }
        {
            window->GetRefWidgetsContainer().AddWidget(GUI::MakeImGUIWidget<SameLine>("SameLine1"));
        }
        {
            auto textBox = GUI::MakeImGUIWidget<TextBox>("Second");
            textBox->SetText("Second!");
            textBox->SetActive(false);
            window->GetRefWidgetsContainer().AddWidget(std::move(textBox));
        }
        {
            auto button = GUI::MakeImGUIWidget<Button>("Button");
            button->SetText("Hello, World!");
            auto slot = button->GetOnPressedSignal().MakeSlot([]()
                {
                    fmt::print("OnButtonClick!");
                });
            button->GetOnPressedSignal().Connect(slot);
            window->GetRefWidgetsContainer().AddWidget(std::move(button));
        }

        _context.GetGUI()->AddWidget(std::move(window));
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
