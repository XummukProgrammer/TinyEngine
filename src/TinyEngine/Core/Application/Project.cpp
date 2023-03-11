#include "Project.hpp"

namespace TinyEngine
{
    void Project::Init()
    {
    }

    void Project::Deinit()
    {
    }

    void Project::Load(const ProjectFileLoadParams& params)
    {
        _projectFile.CreateReflectionObject()->LoadFromFile(params.path);
        OnLoaded();
    }

    void Project::Create(const ProjectFileCreateParams& params)
    {
        _projectFile.InitWithCreateParams(params);
        _projectFile.CreateReflectionObject()->SaveToFile(params.path);
        OnLoaded();
    }

    void Project::OnLoaded()
    {
        Application::GetSingleton().ChangeState(Application::State::ProjectLoaded);
    }

    void ProjectFile::InitWithCreateParams(const ProjectFileCreateParams& params)
    {
        _name = params.name;
        _description = params.description;
        _author = params.author;
        _version = params.version;
        _librariesPath = params.librariesPath;
    }
}
