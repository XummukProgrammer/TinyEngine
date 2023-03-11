#include "ReflectionObject.hpp"

#include <TinyEngine/Core/Application/Application.hpp>

namespace TinyEngine
{
    void ReflectionObject::AddMember(std::unique_ptr<IReflectionMember>&& member)
    {
        _members.push_back(std::move(member));
    }

    bool ReflectionObject::HasMember(std::string_view name) const
    {
        return GetMember(name) != nullptr;
    }

    IReflectionMember* ReflectionObject::GetMember(std::string_view name) const
    {
        auto it = std::find_if(_members.begin(), _members.end(), [name](const std::unique_ptr<IReflectionMember>& member)
        {
            return member->GetName() == name;
        });

        if (it != _members.end())
        {
            return it->get();
        }

        return nullptr;
    }

    void ReflectionObject::ForEachMembers(const std::function<void(IReflectionMember* member)> func)
    {
        for (const auto& member : _members)
        {
            func(member.get());
        }
    }

    void ReflectionObject::Serialize(IOutputArchive* archive)
    {
        ForEachMembers([archive](IReflectionMember* member)
        {
            member->Serialize(archive);
        });
    }

    void ReflectionObject::Deserialize(IInputArchive* archive)
    {
        ForEachMembers([archive](IReflectionMember* member)
        {
            member->Deserialize(archive);
        });
    }

    void ReflectionObject::SaveToFile(FileSystem::DirType dirType, std::wstring_view path)
    {
        SaveToFile(Application::GetSingleton().GetContext().GetFileSystem().BuildPath(dirType, path));
    }

    void ReflectionObject::SaveToFile(std::wstring_view path)
    {
        auto archive = Application::GetSingleton().GetContext().CreateOutputArchive(path);
        archive->WriteKey(GetName());
        Serialize(archive.get());
        archive->EndKey();
        archive->Save();
    }

    void ReflectionObject::LoadFromFile(FileSystem::DirType dirType, std::wstring_view path)
    {
        LoadFromFile(Application::GetSingleton().GetContext().GetFileSystem().BuildPath(dirType, path));
    }

    void ReflectionObject::LoadFromFile(std::wstring_view path)
    {
        auto archive = Application::GetSingleton().GetContext().CreateInputArchive(path);
        archive->Load();
        archive->ReadKey(GetName());
        Deserialize(archive.get());
        archive->EndKey();
    }
}
