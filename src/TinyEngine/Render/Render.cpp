﻿#include "Render.hpp"

#include <TinyEngine/Logger/Logger.hpp>
#include <TinyEngine/Debug/Debug.hpp>
#include <TinyEngine/Render/SfmlRender.hpp>

namespace TinyEngine
{
	Render render;

	Render& Render::CreateSfmlWindow(const RenderWindowSettings& windowSettings, InitSfmlWindowCallback initCallback)
	{
		TINY_ENGINE_INFO("Use Sfml Window");
		CreateWindow(std::make_shared<SfmlRenderWindow>(), windowSettings);
		if (initCallback)
		{
			initCallback(static_cast<SfmlRenderWindow*>(_renderWindowPtr.get()));
		}
		return *this;
	}

	Render& Render::Execute()
	{
		TINY_ENGINE_ASSERT(_renderWindowPtr.get(), "Render Window not inited");

		while (!_renderWindowPtr->IsClosed())
		{
			_renderWindowPtr->ExtractEvents();
			_renderWindowPtr->Update(0.f);
			_renderWindowPtr->Display();
		}

		return *this;
	}

	Render& Render::Destroy()
	{
		_renderWindowPtr.reset();

		return *this;
	}

	void Render::CreateWindow(IRenderWindowPtr window, const RenderWindowSettings& windowSettings)
	{
		_renderWindowPtr = window;
		_renderWindowPtr->Create(windowSettings);
	}
}
