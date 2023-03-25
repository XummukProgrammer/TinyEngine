#include "Application.hpp"

#include <TinyEngine/Core/Application/Project.hpp>
#include <TinyEngine/Core/GUI/GUI.hpp>
#include <TinyEngine/Core/Debug/Debug.hpp>

#include <TinyEngine/Core/GUI/Widgets/MenuBar/MenuBar.hpp>
#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Editor/Debug/DebugWindow.hpp>

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
        _context.GetGUI()->Init();

        ProjectFileCreateParams params;
        params.path = _context.GetFileSystem().BuildPath(FileSystem::Assets, L"project.xml");
        params.name = "TinyEngine";
        params.description = "Game Engine";
        params.author = "Xummuk97";
        params.version = "1.0.0.0 alpha";
        params.librariesPath = "libs.xml";
        _context.GetProject()->Create(params);

        {
            auto menuBar = _context.GetGUI()->GetImGUIMenuBar();

            auto projectMenu = std::make_unique<MenuBarData>();
            projectMenu->SetTitle("Project");

            auto projectCloseAppItem = std::make_unique<MenuBarItem>();
            projectCloseAppItem->SetTitle("Close App");
            projectCloseAppItem->GetOnActionSignal().Connect(projectCloseAppItem->GetOnActionSignal().MakeSlot([this]()
            {
            }));

            projectMenu->AddItem(std::move(projectCloseAppItem));

            menuBar->GetRefMenuContainer().AddMenu(std::move(projectMenu));
        }

        auto debugWindow = _context.GetGUI()->GetMainImGUIWindow()->MakeWidget<DebugWindow>("DebugWindow");
    }

    void Application::Run()
    {
        while (!_window.ShouldClose())
        {
            OnUpdate();

            _window.BeginDrawing();
            _window.ClearBackground(RAYWHITE);
            OnDraw();
            _context.GetGUI()->Draw();
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
        _context.GetDebug()->Init();
        _context.GetProject()->Init();

        DEBUG_INFO("Tiny Engine initialized!");
    }

    void Application::OnDeinit()
    {
        DEBUG_INFO("Tiny Engine destroy");

        _context.GetGUI()->Deinit();
        _context.GetProject()->Deinit();
        _context.GetDebug()->Deinit();
        _context.GetRefFileSystem().Deinit();
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

        DEBUG_INFO("Project loaded! Name: {}, Version: {}", projectFile.GetName(), projectFile.GetVersion());
    }

    void Application::OnStarted()
    {
        DEBUG_INFO("Tiny Engine started!");
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
