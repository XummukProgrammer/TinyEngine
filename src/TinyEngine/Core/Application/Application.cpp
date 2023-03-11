#include "Application.hpp"

#include <TinyEngine/Core/VisualObject/VisualObject.hpp>
#include <TinyEngine/Core/Reflection/ReflectionObject.hpp>

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

    void Application::OnInit()
    {
        _context.GetRefFileSystem().Init();

        class Vector2
        {
        public:
            float x = 0;
            float y = 0;
        };

        Vector2 obj;
        
        ReflectionObject reflectionObject;
        reflectionObject.SetName("obj");

        auto xReflectionMember = std::make_unique<ReflectionMember<float>>();
        xReflectionMember->SetName("x");
        xReflectionMember->SetValue(obj.x);
        reflectionObject.AddMember(std::move(xReflectionMember));

        auto yReflectionMember = std::make_unique<ReflectionMember<float>>();
        yReflectionMember->SetName("y");
        yReflectionMember->SetValue(obj.y);
        reflectionObject.AddMember(std::move(yReflectionMember));

        reflectionObject.SaveToFile(FileSystem::Assets, L"obj.xml");
    }

    void Application::OnDeinit()
    {
        _context.GetRefFileSystem().Deinit();
    }

    void Application::OnUpdate()
    {
    }

    void Application::OnDraw()
    {
        _context.GetRootTransform()->Draw();
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
