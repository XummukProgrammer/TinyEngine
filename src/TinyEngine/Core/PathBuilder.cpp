#include "PathBuilder.hpp"

#include <TinyEngine/Core/Core.hpp>

#include <fmt/format.h>

#include <filesystem>

namespace TinyEngine
{
    std::string PathBuilder::FilePathToDir(std::string_view path) const
    {
        auto fsPath = std::filesystem::path(path);
        std::string newPath = fsPath.remove_filename().generic_string();
        return newPath;
    }

    std::string PathBuilder::GetExecuteFilePath() const
    {
        if (_executeFilePath.empty() && (Core::GetApplication().GetConsoleArgumentCount() > 0))
        {
            _executeFilePath = std::string{Core::GetApplication().GetConsoleArguments()[0]};
        }

        return _executeFilePath;
    }

    std::string PathBuilder::GetExecuteFileDir() const
    {
        if (_executeFileDir.empty())
        {
            const auto& executeFilePath = GetExecuteFilePath();

            if (!executeFilePath.empty())
            {
                _executeFileDir = FilePathToDir(executeFilePath); 
            }           
        }

        return _executeFileDir;
    }

    std::string PathBuilder::GetRootDir() const
    {
        if (_rootDir.empty())
        {
            const auto& executeFileDir = GetExecuteFileDir();

            if (!executeFileDir.empty())
            {
                _rootDir = fmt::format("{}../", executeFileDir);
            }
        }

        return _rootDir;
    }

    std::string PathBuilder::GetBinDir() const
    {
        return GetExecuteFileDir();
    }

    std::string PathBuilder::GetAssetsDir() const
    {
        if (_assetsDir.empty())
        {
            const auto& rootDir = GetRootDir();

            if (!rootDir.empty())
            {
                _assetsDir = fmt::format("{}assets/", rootDir);
            }
        }

        return _assetsDir;
    }

    std::string PathBuilder::GetDirFromType(DirType dirType) const
    {
        switch (dirType)
        {
            case DirType::Root: return GetRootDir();
            case DirType::Bin: return GetBinDir();
            case DirType::Assets: return GetAssetsDir();
        }

        return "";
    }

    std::string PathBuilder::BuildPath(DirType dirType, std::string_view path) const
    {
        return fmt::format("{}{}", GetDirFromType(dirType), path);
    }
}
