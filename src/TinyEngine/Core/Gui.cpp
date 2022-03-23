#include "Gui.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

namespace TinyEngine
{
	void Gui::OnAppQuit()
	{
		ImGui::SFML::Shutdown();

		UnsubscribeAllRenderer();
	}

	void Gui::OnWindowCreated(sf::RenderWindow& renderWindow)
	{ 
		ImGui::SFML::Init(renderWindow);

		auto& io = ImGui::GetIO();
		io.IniFilename = nullptr;
	}

	void Gui::OnWindowUpdated(sf::RenderWindow& renderWindow, const sf::Time& time)
	{ 
		ImGui::SFML::Update(renderWindow, time);

		_guiControllers.OnGuiRenderer();

		GuiRenderedEventParameters params;
		OnRenderer(params);
	}

	void Gui::OnWindowDrawed(sf::RenderWindow& renderWindow)
	{ 
		ImGui::SFML::Render(renderWindow);
	}

	void Gui::OnWindowEvented(sf::RenderWindow& renderWindow, sf::Event& event)
	{ 
		ImGui::SFML::ProcessEvent(renderWindow, event);
	}
}
