#include "WindowLoader.hpp"

#include <TinyEngine/Core/FileSystemManager.hpp>
#include <TinyEngine/Core/Window.hpp>

namespace TinyEngine::Core
{
    static inline const std::string FILE_PATH = "window.xml";
    static inline const DirType DIR_TYPE = DirType::Configs;

    WindowLoader::WindowLoader(WindowInfo* windowInfo)
        : _windowInfo(windowInfo)
    { 
    }

    bool WindowLoader::LoadFromFile(const std::string& filePath)
    {
        pugi::xml_document doc;
        doc.load_file(filePath.c_str());
        auto root = doc.child("root");
        return LoadFromNode(root);
    }

    bool WindowLoader::LoadFromNode(const pugi::xml_node& node)
    {
        if (!_windowInfo)
        {
            return false;
        }

        if (auto settingsNode = node.child("settings"))
        {
            if (auto widthAttribute = settingsNode.attribute("width"))
            {
                _windowInfo->width = widthAttribute.as_uint();
            }

            if (auto heightAttribute = settingsNode.attribute("height"))
            {
                _windowInfo->height = heightAttribute.as_uint();
            }

            if (auto titleAttribute = settingsNode.attribute("title"))
            {
                _windowInfo->title = titleAttribute.as_string();
            }

            if (auto maxFramerateAttribute = settingsNode.attribute("maxFramerate"))
            {
                _windowInfo->maxFramerate = maxFramerateAttribute.as_uint();
            }

            if (auto isVerticalSyncEnabledAttribute = settingsNode.attribute("isVerticalSyncEnabled"))
            {
                _windowInfo->isVerticalSyncEnabled = isVerticalSyncEnabledAttribute.as_bool();
            }
        }

        return true;
    }

    std::string WindowLoader::GetFilePath() const
    {
        return FILE_PATH;
    }

    DirType WindowLoader::GetDirType() const
    {
        return DIR_TYPE;
    }
}
