#include "Project.hpp"

#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Logger.hpp>

#include <fmt/format.h>

namespace TinyEngine
{
	void ProjectUtils::LoadProject(Project* project, std::string_view filePath)
	{
		TINY_ENGINE_PRINT_INFO("Load project...");
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, filePath, project);
		TINY_ENGINE_PRINT_INFO(fmt::format("Loaded project (Name: {}, Description: {}, Version: {}, MainAssetsFile: {})", 
			project->GetName(), project->GetDescription(), project->GetVersion(), project->GetMainAssetsFile()));
		Assets::GetInstance()->LoadFromFile(project->GetMainAssetsFile());
	}
}
