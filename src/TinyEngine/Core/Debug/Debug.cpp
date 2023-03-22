#include "Debug.hpp"

namespace TinyEngine
{
    void DebugLogMessage::Init(std::string_view prefix, std::string_view time, std::string_view text)
    {
        _prefix = prefix;
        _time = time;
        _text = text;
    }

    void DebugLogMessages::SetFilePath(std::wstring_view filePath)
    {
        _filePath = filePath;
    }

    void DebugLogMessages::AddMessage(std::string_view prefix, std::string_view time, std::string_view text)
    {
        auto message = DebugLogMessage();
        message.Init(prefix, time, text);
        
        _messages.push_back(message);
    }

    void DebugLogMessages::Save()
    {
        CreateReflectionObject()->SaveToFile(FileSystem::Logs, _filePath);
    }

    void Debug::Init()
    {
        _allMessages.SetFilePath(L"logs.xml");
        _infoMessages.SetFilePath(L"info.xml");
        _debugMessages.SetFilePath(L"debug.xml");
        _errorMessages.SetFilePath(L"errors.xml");
    }

    void Debug::Deinit()
    {
        Save();
    }

    void Debug::Save()
    {
        _allMessages.Save();
        _infoMessages.Save();
        _debugMessages.Save();
        _errorMessages.Save();
    }

    void Debug::InfoMessage(std::string_view text)
    {
        const auto& time = GetTime();
        _infoMessages.AddMessage("Info", time, text);
        _allMessages.AddMessage("Info", time, text);
    }

    void Debug::DebugMessage(std::string_view text)
    {
        const auto& time = GetTime();
        _debugMessages.AddMessage("Debug", time, text);
        _allMessages.AddMessage("Debug", time, text);
    }

    void Debug::ErrorMessage(std::string_view text)
    {
        const auto& time = GetTime();
        _errorMessages.AddMessage("Error", time, text);
        _allMessages.AddMessage("Error", time, text);
    }

    std::string Debug::GetTime() const
    {
        return "";
    }
}
