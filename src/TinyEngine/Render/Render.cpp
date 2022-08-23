#include "Render.hpp"

#include <TinyEngine/Render/IRenderObject.hpp>
#include <TinyEngine/Render/IRenderWindow.hpp>
#include <TinyEngine/Render/SfmlRender.hpp>

#include <TinyEngine/Gui/Gui.hpp>

#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/Debug.hpp>

namespace TinyEngine
{
	Render& Render::CreateSfmlWindow(const RenderWindowSettings& windowSettings)
	{
		TINY_ENGINE_PRINT_INFO("Use Sfml Window");
		CreateWindow(std::make_shared<SfmlRenderWindow>(), windowSettings);
		return *this;
	}

	Render& Render::Execute()
	{
		TINY_ENGINE_ASSERT(_renderWindowPtr.get(), "Render Window not inited");

		_renderWindowPtr->ResetClock();

		while (!_renderWindowPtr->IsClosed())
		{
			_renderWindowPtr->UpdateClock();
			const float deltaTime = _renderWindowPtr->GetDeltaTime();

			_renderWindowPtr->ExtractEvents();

			Update(deltaTime);

			_renderWindowPtr->Clear();
			Draw(_renderWindowPtr);
			_renderWindowPtr->Display();
		}

		Gui::GetInstance()->Shutdown(_renderWindowPtr);

		return *this;
	}

	Render& Render::Destroy()
	{
		TINY_ENGINE_PRINT_INFO("Destroy");

		_renderWindowPtr.reset();

		return *this;
	}

	void Render::Close()
	{
		_renderWindowPtr->Close();
	}

	void Render::Update(float deltaTime)
	{
		_renderLayers.Update(deltaTime);

		auto gui = Gui::GetInstance();
		gui->Update(deltaTime, _renderWindowPtr);
		gui->Draw(deltaTime, _renderWindowPtr);
	}

	void Render::Draw(IRenderWindowSharedPtr window)
	{
		_renderLayers.Draw(window);

		Gui::GetInstance()->Display(_renderWindowPtr);
	}

	void Render::OnEventReceived()
	{
		Gui::GetInstance()->EventReceived(_renderWindowPtr);
	}

	void Render::CreateWindow(IRenderWindowSharedPtr window, const RenderWindowSettings& windowSettings)
	{
		_renderWindowPtr = window;
		_renderWindowPtr->Create(windowSettings);
		_renderWindowPtr->SetOnEventReceived(std::bind(&Render::OnEventReceived, this));

		auto gui = Gui::GetInstance();
		gui->SetDelegate(_renderWindowPtr->CreateDelegate());
		gui->Init(_renderWindowPtr);
	}
}
