﻿#include "Project.hpp"

#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/World/World.hpp>

#include <fmt/format.h>

namespace TinyEngine
{
	void ProjectUtils::LoadProject(Project* project, std::string_view filePath, World* world)
	{
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, filePath, project);
		Assets::GetInstance()->LoadFromFile(project->GetMainAssetsFile());
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, project->GetWorldFile(), world);
		world->OnInit();
	}
}
