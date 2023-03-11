#include "Application.hpp"

#include <TinyEngine/Core/VisualObject/VisualObject.hpp>
#include <TinyEngine/Core/Reflection/ReflectionObject.hpp>
#include <TinyEngine/Core/Reflection/ReflectionMember.hpp>

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

        class Vector2 : public ReflectionObjectCreator
        {
            REFLECTION_OBJECT_BEGIN(Vector2)
                REFLECTION_MEMBER("x", x)
                REFLECTION_MEMBER("y", y)
            REFLECTION_OBJECT_END

        public:
            float x = 0;
            float y = 0;
        };

        class Rect : public ReflectionObjectCreator
        {
        public:
            REFLECTION_OBJECT_BEGIN(Rect)
                REFLECTION_MEMBER("pos", pos)
                REFLECTION_MEMBER("size", size)
                REFLECTION_MEMBER("test", test)
            REFLECTION_OBJECT_END

        public:
            Vector2 pos;
            Vector2 size;
            std::vector<Vector2> test;
        };

        Rect obj;

        obj.test.push_back(Vector2());
        obj.test.back().x = 99.24f;
        obj.test.back().y = 12.50f;

        obj.test.push_back(Vector2());
        obj.test.back().x = 51.21f;
        obj.test.back().y = 24.26f;

        obj.CreateReflectionObject()->SaveToFile(FileSystem::Assets, L"obj.xml");
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
