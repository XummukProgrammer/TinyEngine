#include "Render.hpp"

#include <TinyEngine/Core/Render/RenderObject.hpp>
#include <TinyEngine/Core/Render/RenderWindow.hpp>

#include <TinyEngine/Core/Gui/Gui.hpp>

#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/Debug.hpp>

#include <TinyEngine/Core/Render/RenderLayer.hpp>

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
	Render& Render::Execute()
	{
		while (!RenderWindow::GetInstance()->IsClosed())
		{
			const float deltaTime = 0.f;

			Update(deltaTime);

			if (!Application::GetInstance()->IsClose())
			{
				RenderWindow::GetInstance()->Begin();
				RenderWindow::GetInstance()->Clear();
				Draw();
				RenderWindow::GetInstance()->End();
			}
		}

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
		Gui::GetInstance()->Shutdown();
		RenderWindow::GetInstance()->Close();
	}

	void Render::Update(float deltaTime)
	{
		_renderLayers.Update(deltaTime);

		OnUpdate();
	}

	void Render::Draw()
	{
		_renderLayers.Draw();

		Gui::GetInstance()->Draw();
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

		auto gui = Gui::GetInstance();
		gui->Init();
	}
}
