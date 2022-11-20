﻿#include "Project.hpp"

#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/World/World.hpp>

#include <TinyEngine/Core/Application.hpp>
#include <TinyEngine/Core/Conditions/ConditionVariable.hpp>

#include <iostream>

namespace TinyEngine
{
	void ProjectUtils::LoadProject(Project* project, std::string_view filePath, World* world)
	{
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, filePath, project);
		Assets::GetInstance()->LoadFromFile(project->GetMainAssetsFile());
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, project->GetWorldFile(), world);
		world->OnInit();
		project->SetFilePath(filePath);

		if (auto condition = project->GetCondition())
		{
			auto localVariableA = std::make_shared<ConditionIntVariable>();
			localVariableA->SetValue(6);
			condition->GetLocalContext().AddVariable("A", localVariableA);

			condition->OnInit();
			std::cout << "Condition Is Result: " << (condition->IsResult() ? "true" : "false") << std::endl;
		}
	}

	void ProjectUtils::SaveProject(Project* project)
	{
		SerializationUtils::SaveRootToFile(ArchiveFormat::Xml, project->GetFilePath(), project);
	}
}
