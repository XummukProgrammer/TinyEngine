#include "GuiController.hpp"

namespace TinyEngine
{
	void GuiController::OnGuiRenderer()
	{ 
		GetView().OnGuiRenderer(GetModel());
	}
}
