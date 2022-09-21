#include <TinyEngine/Gui/Gui.hpp>

#include <TinyEngine/Render/RenderWindow.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

namespace TinyEngine
{
	void Gui::PreInit()
	{
		auto& renderWindow = *RenderWindow::GetInstance()->GetRenderWindow();
		ImGui::SFML::Init(renderWindow);
	}

	void Gui::EventReceived()
	{
		auto& renderWindow = *RenderWindow::GetInstance()->GetRenderWindow();
		auto& event = RenderWindow::GetInstance()->GetEvent();
		ImGui::SFML::ProcessEvent(renderWindow, event);
	}

	void Gui::Update(float deltaTime)
	{
		auto& renderWindow = *RenderWindow::GetInstance()->GetRenderWindow();
		ImGui::SFML::Update(renderWindow, sf::seconds(deltaTime));
	}

	void Gui::Display()
	{
		auto& renderWindow = *RenderWindow::GetInstance()->GetRenderWindow();
		ImGui::SFML::Render(renderWindow);
	}

	void Gui::Shutdown()
	{
		ImGui::SFML::Shutdown();
	}
}
