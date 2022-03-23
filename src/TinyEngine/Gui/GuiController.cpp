#include "GuiController.hpp"

namespace TinyEngine
{
	void GuiController::OnAppEntry()
	{
		OnInit();
	}

	void GuiController::OnAppQuit()
	{ 
		OnDeinit();
	}

	void GuiController::OnInit()
	{
		GetModel().OnInit();
		GetModel().isEnabled.SubscribeValueChanged(std::bind(&GuiController::OnIsEnableChanged, this, std::placeholders::_1));
		OnEnable();
	}

	void GuiController::OnDeinit()
	{ 
		GetModel().OnDeinit();
	}

	void GuiController::OnGuiRenderer()
	{ 
		GetView().OnGuiRenderer(GetModel());
	}

	void GuiController::OnIsEnableChanged(BoolEventableValue::ValueChangedParametersTemplate& params)
	{
		if (params.currentValue)
		{
			OnEnable();
		}
		else
		{
			OnDisable();
		}
	}
}
