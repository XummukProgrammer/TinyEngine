#include "GuiModel.hpp"

namespace TinyEngine
{
	void GuiModel::OnInit()
	{ 
		isEnabled.SetValue(true);
	}

	void GuiModel::OnDeinit()
	{ 
		isEnabled.UnsubscribeAllValueChanged();
	}
}
