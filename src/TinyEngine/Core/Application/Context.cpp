#include "Context.hpp"

#include <TinyEngine/Core/Serialization/XmlArchive.hpp>
#include <TinyEngine/Core/Application/Project.hpp>
#include <TinyEngine/Core/GUI/GUI.hpp>
#include <TinyEngine/Core/Debug/Debug.hpp>

namespace TinyEngine
{
    std::unique_ptr<IInputArchive> Context::CreateInputArchive(FileSystem::DirType dirType, std::wstring_view path) const
    {
        return std::move(CreateInputArchive(_fileSystem.BuildPath(dirType, path)));
    }

    std::unique_ptr<IInputArchive> Context::CreateInputArchive(std::wstring_view path) const
    {
        auto archive = std::make_unique<XmlInputArchive>();
        archive->SetPath(path);
        return std::move(archive);
    }

    std::unique_ptr<IOutputArchive> Context::CreateOutputArchive(FileSystem::DirType dirType, std::wstring_view path) const
    {
        return std::move(CreateOutputArchive(_fileSystem.BuildPath(dirType, path)));
    }

    std::unique_ptr<IOutputArchive> Context::CreateOutputArchive(std::wstring_view path) const
    {
        auto archive = std::make_unique<XmlOutputArchive>();
        archive->SetPath(path);
        return std::move(archive);
    }

    Project* Context::GetProject() const
    {
        static Project project;
        return &project;
    }

    GUI* Context::GetGUI() const
    {
        static GUI gui;
        return &gui;
    }

    Debug* Context::GetDebug() const
    {
        static Debug debug;
        return &debug;
    }
}
