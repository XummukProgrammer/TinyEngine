#include "Application.hpp"

#include <TinyEngine/Core/Application/Project.hpp>

#include <fmt/format.h>
#include "rlImGui.h"

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
            ImGui::Text("Hello, World!");
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
