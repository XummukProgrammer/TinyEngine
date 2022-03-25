#include "PathBuilder.hpp"

#include <TinyEngine/Core/Core.hpp>

#include <filesystem>

namespace TinyEngine
{
    std::string PathBuilder::GetExecuteFilePath() const
    {
        if (Core::GetApplication().GetConsoleArgumentCount() > 0)
        {
            static std::string executeFilePath = std::string{Core::GetApplication().GetConsoleArguments()[0]};
            return executeFilePath;
        }

        return "";
    }

    std::string PathBuilder::GetExecuteFileDir() const
    {
        static std::string executeFileDir;

        if (executeFileDir.empty())
        {
            const auto& executeFilePath = GetExecuteFilePath();

            if (!executeFilePath.empty())
            {
                auto path = std::filesystem::path(executeFilePath);
                executeFileDir = path.remove_filename().generic_string(); 
            }           
        }

        return executeFileDir;
    }
}
