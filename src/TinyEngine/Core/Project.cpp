#include "Project.hpp"

#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/World/World.hpp>
#include <TinyEngine/Core/Application.hpp>
#include <TinyEngine/Core/FileSystem.hpp>

namespace TinyEngine
{
	void ProjectUtils::LoadProject(std::string_view filePath)
	{
		auto& project = Application::GetInstance()->GetProject();
		auto& world = Application::GetInstance()->GetWorld();

		FileSystem::GetInstance()->SetProjectPath(filePath);

		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, filePath, &project, true);

		project.GetLinkAsset().OnAssetLoad();
		world.OnInit();
		project.GetStates().OnInit();
	}

	void ProjectUtils::SaveProject()
	{
		auto& project = Application::GetInstance()->GetProject();
		SerializationUtils::SaveRootToFile(ArchiveFormat::Xml, FileSystem::GetInstance()->GetProjectPath(), &project, true);
	}
}
