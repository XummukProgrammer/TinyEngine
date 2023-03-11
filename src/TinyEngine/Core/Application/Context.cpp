#include "Context.hpp"

#include <TinyEngine/Core/Serialization/XmlArchive.hpp>

namespace TinyEngine
{
    std::unique_ptr<IInputArchive> Context::CreateInputArchive(FileSystem::DirType dirType, std::wstring_view path) const
    {
        return nullptr;
    }

    std::unique_ptr<IOutputArchive> Context::CreateOutputArchive(FileSystem::DirType dirType, std::wstring_view path) const
    {
        auto inputArchive = std::make_unique<XmlOutputArchive>();
        inputArchive->SetPath(_fileSystem.BuildPath(dirType, path));
        return std::move(inputArchive);
    }
}
