#include "Application.hpp"

#include <TinyEngine/Core/VisualObject/Transform.hpp>

#include <fmt/format.h>

namespace TinyEngine
{
    void Application::Load()
    {
    }

    void Application::Create()
    {
        _window.Init(_context.GetScreenWidth(), _context.GetScreenHeight(), _context.GetWindowTitle());
    }

    void Application::Run()
    {
        while (!_window.ShouldClose())
        {
            _window.BeginDrawing();

            _window.ClearBackground(RAYWHITE);

            _window.EndDrawing();
        }
    }

    void Application::Stop()
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

        Application application;
        application.SetContext(context);
        application.Load();
        application.Create();
        application.Run();
    }
}
