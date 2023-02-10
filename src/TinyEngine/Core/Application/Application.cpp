﻿#include "Application.hpp"

#include <TinyEngine/Core/VisualObject/VisualObject.hpp>

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
        context.SetIsDrawGizmos(true);

        auto& application = Application::GetSingleton();
        application.SetContext(context);

        application.Load();
        application.Create();

        auto rootTransform = application.GetRootTransform();
        rootTransform->SetLocalPosition({ 250, 250 });
        rootTransform->SetLocalScale({ 8, 8 });
        {
            rootTransform->SetLayout(std::make_shared<VerticalLayout>());
        }

        {
            auto attached = std::make_shared<TinyEngine::VisualObject>();
            attached->SetLocalScale({ 3, 1 });
            attached->Load("rectangle.png");
            rootTransform->Attach(attached);
        }
        {
            auto attached = std::make_shared<TinyEngine::Transform>();
            attached->SetLocalScale({ 3, 1 });
            rootTransform->Attach(attached);
        }
        {
            auto attached = std::make_shared<TinyEngine::VisualObject>();
            attached->SetLocalScale({ 3, 1 });
            attached->Load("rectangle.png");
            rootTransform->Attach(attached);
        }
        {
            auto attached = std::make_shared<TinyEngine::Transform>();
            attached->SetLocalScale({ 3, 1 });
            rootTransform->Attach(attached);
        }
        {
            auto attached = std::make_shared<TinyEngine::Transform>();
            attached->SetLocalScale({ 3, 1 });
            rootTransform->Attach(attached);
        }
        {
            auto attached = std::make_shared<TinyEngine::Transform>();
            attached->SetLocalScale({ 3, 1 });
            rootTransform->Attach(attached);
        }

        
        application.Run();
    }
}
