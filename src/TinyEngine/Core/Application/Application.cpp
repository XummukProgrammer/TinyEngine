#include "Application.hpp"

#include <fmt/format.h>

namespace TinyEngine
{
    Application Application::_singleton;

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

            if (_rootTransform)
            {
                _rootTransform->Draw();
            }

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
        context.SetScalePixelCoef(50);

        auto& application = Application::GetSingleton();
        application.SetContext(context);

        auto rootTransform = application.GetRootTransform();
        rootTransform->SetLocalPosition({ 250, 250 });
        rootTransform->SetLocalScale({ 7, 7 });

        auto attached1 = std::make_shared<TinyEngine::Transform>();
        attached1->SetLocalPosition({ 0, -150 });
        attached1->SetLocalScale({ 6.5, 0.85 });
        rootTransform->Attach(attached1);

        application.Load();
        application.Create();
        application.Run();
    }
}
