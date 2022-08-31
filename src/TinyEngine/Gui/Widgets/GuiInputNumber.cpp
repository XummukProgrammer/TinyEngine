#include "GuiInputNumber.hpp"

namespace TinyEngine
{
	GuiInputNumberSharedPtr GuiInputNumber::Create(std::string_view title, int value, const OnInputed& callback)
	{
		auto widget = std::make_shared<GuiInputNumber>();
		widget->SetTitle(title);
		widget->SetValue(value);
		widget->SetOnInputedCallback(callback);
		return widget;
	}

	void GuiInputNumber::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
	{
		ImGui::PushID(_title.c_str());
		if (ImGui::InputInt(_title.c_str(), &_value) && _onInputedCallback)
		{
			_onInputedCallback(_value);
		}
		ImGui::PopID();
	}
}
