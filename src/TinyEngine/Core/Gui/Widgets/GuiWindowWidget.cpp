#include "GuiWindowWidget.hpp"

#include <TinyEngine/Core/Gui/Widgets/GuiFileBrowserWidget.hpp>

namespace TinyEngine
{
	GuiWindowWidgetSharedPtr GuiWindowWidget::Create(std::string_view name)
	{
		auto widget = std::make_shared<GuiWindowWidget>();
		widget->SetName(name);
		return widget;
	}

	void GuiWindowWidget::Draw(float deltaTime)
	{
		GuiWidget::Draw(deltaTime);

		BeginWindow();

		GuiWidgetContainer::Draw(deltaTime);

		EndWindow();
	}

	void GuiWindowWidget::BeginWindow()
	{
		ImGui::Begin(_name.c_str());
	}

	void GuiWindowWidget::EndWindow()
	{
		ImGui::End();
	}

	GuiMainWindowWidgetSharedPtr GuiMainWindowWidget::Create()
	{
		auto widget = std::make_shared<GuiMainWindowWidget>();
		widget->SetMenuBar(GuiMenuBarWidget::Create());
		widget->SetFileBrowser(GuiFileBrowserWidget::Create());
		return widget;
	}

	void GuiMainWindowWidget::SetMenuBar(GuiMenuBarWidgetSharedPtr menuBarPtr)
	{
		_menuBarPtr = menuBarPtr;
		AddWidget("menuBar", _menuBarPtr);
	}

	void GuiMainWindowWidget::SetFileBrowser(GuiFileBrowserWidgetSharedPtr widget)
	{
		_fileBrowserWidget = widget;
		AddWidget("fileBrowser", _fileBrowserWidget);
	}

	void GuiMainWindowWidget::BeginWindow()
	{
        ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar;
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		window_flags |= ImGuiWindowFlags_NoBackground;
		dockspace_flags |= ImGuiDockNodeFlags_PassthruCentralNode;

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("DockSpace Demo", nullptr, window_flags);

        ImGui::PopStyleVar();

        ImGui::PopStyleVar(2);

        // Submit the DockSpace
        ImGuiIO& io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
        }
	}

	void GuiMainWindowWidget::EndWindow()
	{
		ImGui::End();

		//ImGui::ShowDemoWindow();
	}
}
