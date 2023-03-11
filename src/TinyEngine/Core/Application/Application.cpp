﻿#include "Application.hpp"

#include <TinyEngine/Core/Application/Project.hpp>

#include <fmt/format.h>

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
    }

    void Application::Run()
    {
        while (!_window.ShouldClose())
        {
            OnUpdate();

            _window.BeginDrawing();
            _window.ClearBackground(RAYWHITE);
            OnDraw();
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

        ProjectFileCreateParams params;
        params.path = _context.GetFileSystem().BuildPath(FileSystem::Assets, L"project.xml");
        params.name = "TinyEngine";
        params.description = "Game Engine";
        params.author = "Xummuk97";
        params.version = "1.0.0.0 alpha";
        params.librariesPath = "libs.xml";
        _context.GetProject()->Create(params);
    }

    void Application::OnDeinit()
    {
        _context.GetRefFileSystem().Deinit();
        _context.GetProject()->Deinit();
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
        context.SetWindowTitle(fmt::format("TinyEngine {0}", applicationVersion));
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
