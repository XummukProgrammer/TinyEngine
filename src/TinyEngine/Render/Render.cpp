#include "Render.hpp"

#include <TinyEngine/Render/RenderObject.hpp>
#include <TinyEngine/Render/RenderWindow.hpp>

#include <TinyEngine/Gui/Gui.hpp>

#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/Debug.hpp>

namespace TinyEngine
{
	Render& Render::Execute()
	{
		RenderWindow::GetInstance()->ResetClock();

		while (!RenderWindow::GetInstance()->IsClosed())
		{
			RenderWindow::GetInstance()->UpdateClock();
			const float deltaTime = RenderWindow::GetInstance()->GetDeltaTime();

			RenderWindow::GetInstance()->ExtractEvents();

			Update(deltaTime);

			RenderWindow::GetInstance()->Clear();
			Draw();
			RenderWindow::GetInstance()->Display();
		}

		Gui::GetInstance()->Shutdown();

		return *this;
	}

	Render& Render::Destroy()
	{
		TINY_ENGINE_PRINT_INFO("Destroy");

		RenderWindow::ResetInstance();

		return *this;
	}

	void Render::Close()
	{
		RenderWindow::GetInstance()->Close();
	}

	void Render::Update(float deltaTime)
	{
		_renderLayers.Update(deltaTime);

		auto gui = Gui::GetInstance();
		gui->Update(deltaTime);
		gui->Draw(deltaTime);
	}

	void Render::Draw()
	{
		_renderLayers.Draw();

		Gui::GetInstance()->Display();
	}

	void Render::OnEventReceived()
	{
		Gui::GetInstance()->EventReceived();
	}

	void Render::CreateWindow(const RenderWindowSettings& windowSettings)
	{
		RenderWindow::GetInstance()->Create(windowSettings);
		RenderWindow::GetInstance()->SetOnEventReceived(std::bind(&Render::OnEventReceived, this));

		auto gui = Gui::GetInstance();
		gui->Init();
	}
}
