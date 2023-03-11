#include "ReflectionObject.hpp"

namespace TinyEngine
{
    void ReflectionObject::AddMember(std::string_view name, std::unique_ptr<IReflectionMember>&& member)
    {
        member->SetName(name);
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
}
