#include "Project.hpp"

#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/World/World.hpp>
#include <TinyEngine/Core/ServiceProviders/ServiceProviders.hpp>

#include <fmt/format.h>

namespace TinyEngine
{
	void ProjectUtils::LoadProject(Project* project, std::string_view filePath)
	{
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, filePath, project);
		Assets::GetInstance()->LoadFromFile(project->GetMainAssetsFile());
		if (auto world = ServiceProviders::GetInstance()->GetProvider<IWorldServiceProvider>())
		{
			world->LoadWorld();
		}
		project->SetFilePath(filePath);
	}

	void ProjectUtils::SaveProject(Project* project)
	{
		SerializationUtils::SaveRootToFile(ArchiveFormat::Xml, project->GetFilePath(), project);
	}
}
