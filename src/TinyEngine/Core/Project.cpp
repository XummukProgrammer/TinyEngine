#include "Project.hpp"

#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/World/World.hpp>
#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
	void ProjectUtils::LoadProject(std::string_view filePath)
	{
		auto& project = Application::GetInstance()->GetProject();
		auto& world = Application::GetInstance()->GetWorld();

		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, filePath, &project, false);
		Assets::GetInstance()->LoadFromFile(project.GetMainAssetsFile());
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, project.GetWorldFile(), &world);

		world.OnInit();
		project.SetFilePath(filePath);
		project.GetStates().OnInit();
	}

	void ProjectUtils::SaveProject()
	{
		auto& project = Application::GetInstance()->GetProject();
		SerializationUtils::SaveRootToFile(ArchiveFormat::Xml, project.GetFilePath(), &project);
	}
}
