#include "Application.hpp"

#include <TinyEngine/Core/VisualObject/VisualObject.hpp>

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

        auto testOutputArchive = _context.CreateOutputArchive(FileSystem::DirType::Assets, L"test.xml");
        testOutputArchive->WriteKey("test");
        testOutputArchive->WriteInt("int", 123);
        testOutputArchive->WriteFloat("float", 12.24f);
        testOutputArchive->WriteString("string", "Hello, World!");
        testOutputArchive->EndKey();
        testOutputArchive->Save();
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
