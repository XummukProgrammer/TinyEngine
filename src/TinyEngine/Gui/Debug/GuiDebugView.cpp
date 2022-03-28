#include "GuiDebugView.hpp"

#include <TinyEngine/Gui/Debug/GuiDebugModel.hpp>

#include <fmt/format.h>

namespace TinyEngine
{
	void GuiDebugView::OnGuiRenderer(const GuiModel& model)
	{ 
		const auto& debugModel = static_cast<const GuiDebugModel&>(model);
		
		ImGui::Begin("Debug");
		ImGui::SetWindowSize({ 500, 500 });

		ImGui::Text("App:");
		ImGui::Text(fmt::format("Name: {}", debugModel.GetAppName()).c_str());
		ImGui::Text(fmt::format("Version: {}", debugModel.GetAppVersion()).c_str());
		ImGui::Text(fmt::format("Fps: {}", debugModel.GetFpsCounter()).c_str());
		ImGui::NewLine();

		ImGui::Text("Render:");
		ImGui::Text(fmt::format("Layouts count: {}", debugModel.GetLayoutsCount()).c_str());
		ImGui::Text(fmt::format("Objects count: {}", debugModel.GetObjectsCount()).c_str());
		ImGui::NewLine();

		ImGui::Text("Actions:");
		for (const auto& actionId : debugModel.GetActionsIds())
		{
			ImGui::Text(actionId.c_str());
		}
		ImGui::NewLine();

		ImGui::End();
	}
}
