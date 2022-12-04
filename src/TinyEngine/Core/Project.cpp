#include "Project.hpp"

#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/World/World.hpp>
#include <TinyEngine/Core/Application.hpp>
#include <TinyEngine/Core/FileSystem.hpp>
#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Gui/Widgets/Containers/GuiPropertiesWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiWindowWidget.hpp>
#include <TinyEngine/Core/Gui/Gui.hpp>

namespace TinyEngine
{
	StatesSharedPtr Project::GetStates() const
	{
		static StatesSharedPtr states;
		if (!states)
		{
			states = Assets::GetInstance()->GetAsset<States>("States");
		}
		return states;
	}

	void ProjectUtils::LoadProject(std::string_view filePath)
	{
		auto& project = Application::GetInstance()->GetProject();
		auto& world = Application::GetInstance()->GetWorld();

		FileSystem::GetInstance()->SetProjectPath(filePath);

		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, filePath, &project, false);

		project.GetAssetHolder().OnAssetLoad();
		world.OnInit();

		if (auto states = project.GetStates())
		{
			states->OnInit();
		}

		auto mainWindowWidgetPtr = TinyEngine::Gui::GetInstance()->GetMainWindow();
		auto propertiesWindow = mainWindowWidgetPtr->GetWidget<GuiPropertiesWidget>("Properties");
		propertiesWindow->InitFromMetaClass(&TinyEngine::Application::GetInstance()->GetProject());
	}

	void ProjectUtils::SaveProject()
	{
		auto& project = Application::GetInstance()->GetProject();
		const auto& projectPath = FileSystem::GetInstance()->GetProjectPath();
		SerializationUtils::SaveRootToFile(ArchiveFormat::Xml, projectPath, &project, false);

		Assets::GetInstance()->SaveAllAssets();
	}
}
