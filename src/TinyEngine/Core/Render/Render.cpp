#include "Render.hpp"

#include <TinyEngine/Core/Render/RenderObject.hpp>
#include <TinyEngine/Core/Render/RenderWindow.hpp>

#include <TinyEngine/Core/Gui/Gui.hpp>

#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/Debug.hpp>

#include <TinyEngine/Core/Render/RenderLayer.hpp>

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
		RenderWindow::ResetInstance();

		return *this;
	}

	void Render::ChangeObjectLayer(RenderObjectSharedPtr object, int newLayerId)
	{
		if (!object)
		{
			return;
		}

		if (auto layer = _renderLayers.GetLayer(object->GetLayerId()))
		{
			layer->RemoveRenderObject(object);
		}

		if (auto layer = _renderLayers.GetOrCreateLayer(newLayerId))
		{
			layer->AddRenderObject(object);
		}
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

		OnUpdate();
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

	void Render::OnUpdate()
	{
		if (_onUpdateCallback)
		{
			_onUpdateCallback();
		}
	}

	void Render::CreateWindow(const RenderWindowSettings& windowSettings)
	{
		RenderWindow::GetInstance()->Create(windowSettings);
		RenderWindow::GetInstance()->SetOnEventReceived(std::bind(&Render::OnEventReceived, this));

		auto gui = Gui::GetInstance();
		gui->Init();
	}
}
