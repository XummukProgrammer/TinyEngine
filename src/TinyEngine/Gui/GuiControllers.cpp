#include "GuiControllers.hpp"

namespace TinyEngine
{
	void GuiControllers::OnAppEntry()
	{ 
		for (const auto& controller : _controllers)
		{
			controller->OnAppEntry();
		}
	}

	void GuiControllers::OnAppQuit()
	{ 
		for (const auto& controller : _controllers)
		{
			controller->OnAppQuit();
		}
	}

	void GuiControllers::OnGuiRenderer()
	{ 
		for (const auto& controller : _controllers)
		{
			if (controller->GetModel().isEnabled.GetValue())
			{
				controller->OnGuiRenderer();
			}
		}
	}
}
