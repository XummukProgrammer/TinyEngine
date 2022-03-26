#include "GuiDebugView.hpp"

#include <TinyEngine/Gui/Debug/GuiDebugModel.hpp>

#include <fmt/format.h>

namespace TinyEngine
{
	void GuiDebugView::OnGuiRenderer(const GuiModel& model)
	{ 
		const auto& debugModel = static_cast<const GuiDebugModel&>(model);
		
		ImGui::Begin("Debug");
		ImGui::Text(fmt::format("App name: {}", debugModel.GetAppName()).c_str());
		ImGui::Text(fmt::format("App version: {}", debugModel.GetAppVersion()).c_str());
		ImGui::Text(fmt::format("Fps: {}", debugModel.GetFpsCounter()).c_str());
		ImGui::Text(fmt::format("Layouts count: {}", debugModel.GetLayoutsCount()).c_str());
		ImGui::End();
	}
}
