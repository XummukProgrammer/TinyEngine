#include "SfmlGuiDelegate.hpp"

#include <TinyEngine/Render/SfmlRender.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

namespace TinyEngine
{
	void SfmlGuiDelegate::Init(IRenderWindowSharedPtr renderWindowPtr)
	{
		auto& renderWindow = *static_cast<SfmlRenderWindow*>(renderWindowPtr.get())->GetRenderWindow();
		ImGui::SFML::Init(renderWindow);
	}

	void SfmlGuiDelegate::EventReceived(IRenderWindowSharedPtr renderWindowPtr)
	{
		auto window = static_cast<SfmlRenderWindow*>(renderWindowPtr.get());
		auto& renderWindow = *window->GetRenderWindow();
		const auto& event = window->GetEvent();
		ImGui::SFML::ProcessEvent(renderWindow, event);
	}

	void SfmlGuiDelegate::Update(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
	{
		auto& renderWindow = *static_cast<SfmlRenderWindow*>(renderWindowPtr.get())->GetRenderWindow();
		ImGui::SFML::Update(renderWindow, sf::seconds(deltaTime));
	}

	void SfmlGuiDelegate::Display(IRenderWindowSharedPtr renderWindowPtr)
	{
		auto& renderWindow = *static_cast<SfmlRenderWindow*>(renderWindowPtr.get())->GetRenderWindow();
		ImGui::SFML::Render(renderWindow);
	}

	void SfmlGuiDelegate::Shutdown(IRenderWindowSharedPtr renderWindowPtr)
	{
		ImGui::SFML::Shutdown();
	}
}
