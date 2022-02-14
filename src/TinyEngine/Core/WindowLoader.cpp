#include "WindowLoader.hpp"

#include <TinyEngine/Core/FileSystemManager.hpp>
#include <TinyEngine/Core/Window.hpp>
#include <TinyEngine/Utils/XmlUtils.hpp>

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
            _windowInfo->width = Utils::XmlUtils::GetAttributeUnsignedOrDefault(settingsNode, "width", 800);
            _windowInfo->height = Utils::XmlUtils::GetAttributeUnsignedOrDefault(settingsNode, "height", 600);
            _windowInfo->title = Utils::XmlUtils::GetAttributeStringOrDefault(settingsNode, "title", "TinyEngine");
            _windowInfo->maxFramerate = Utils::XmlUtils::GetAttributeUnsignedOrDefault(settingsNode, "maxFramerate", 60);
            _windowInfo->isVerticalSyncEnabled = Utils::XmlUtils::GetAttributeBoolOrDefault(settingsNode, "isVerticalSyncEnabled", false);
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
