#include "GuiControllers.hpp"

namespace TinyEngine
{
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
