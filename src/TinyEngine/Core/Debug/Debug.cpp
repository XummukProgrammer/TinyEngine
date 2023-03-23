#include "Debug.hpp"

#include <TinyEngine/Core/Data/Time.hpp>
#include <TinyEngine/Core/Data/String.hpp>

#include <TinyEngine/Core/Application/Application.hpp>

#include <iostream>

namespace TinyEngine
{
    void DebugLogMessage::Init(std::string_view prefix, std::string_view time, std::string_view function, std::string_view text)
    {
        _prefix = prefix;
        _time = time;
        _function = function;
        _text = text;
    }

    std::string DebugLogMessage::GetString(bool isShowPrefix, bool isShowTime, bool isShowFunction) const
    {
        std::string str;
        if (isShowPrefix)
        {
            str += "[" + _prefix + "] ";
        }
        if (isShowTime)
        {
            str += "[" + _time + "] ";
        }
        if (isShowFunction)
        {
            str += "[" + _function + "] ";
        }
        str += _text;
        return str;
    }

    void DebugLogMessages::SetFilePath(std::wstring_view filePath)
    {
        _filePath = filePath;
    }

    DebugLogMessage& DebugLogMessages::AddMessage(std::string_view prefix, std::string_view time, std::string_view function, std::string_view text)
    {
        auto message = DebugLogMessage();
        message.Init(prefix, time, function, text);
        _messages.push_back(message);

        OnMessageAdded(message);

        return _messages.back();
    }

    void DebugLogMessages::Save()
    {
        CreateReflectionObject()->SaveToFile(FileSystem::Logs, _filePath);
    }

    void DebugLogMessages::OnMessageAdded(const DebugLogMessage& message)
    {
        _onMessageAddedSignal.Emit(message);
    }

    void Debug::Init()
    {
        _messages[DebugLogMessagesType::All] = std::make_unique<DebugLogMessages>();
        _messages[DebugLogMessagesType::Info] = std::make_unique<DebugLogMessages>();
        _messages[DebugLogMessagesType::Debug] = std::make_unique<DebugLogMessages>();
        _messages[DebugLogMessagesType::Error] = std::make_unique<DebugLogMessages>();

        for (const auto& messages : _messages)
        {
            messages.second->SetFilePath(GetFilePathByMessagesType(messages.first));
        }
    }

    void Debug::Deinit()
    {
        Save();
    }

    void Debug::Save()
    {
        for (const auto& messages : _messages)
        {
            messages.second->Save();
        }
    }

    void Debug::InfoMessage(std::string_view function, std::string_view text)
    {
        Log({ DebugLogMessagesType::All, DebugLogMessagesType::Info }, "Info", function, text);
    }

    void Debug::DebugMessage(std::string_view function, std::string_view text)
    {
        Log({ DebugLogMessagesType::All, DebugLogMessagesType::Debug }, "Debug", function, text);
    }

    void Debug::ErrorMessage(std::string_view function, std::string_view text)
    {
        Log({ DebugLogMessagesType::All, DebugLogMessagesType::Error }, "Error", function, text);
    }

    DebugLogMessages* Debug::GetDebugLogMessages(DebugLogMessagesType type) const
    {
        return _messages.at(type).get();
    }

    std::string Debug::GetTime() const
    {
        const auto& time = Time().GetNowTimeString();
        return String(time).Replace("\n", "").Get();
    }

    std::wstring Debug::GetFilePathByMessagesType(DebugLogMessagesType type) const
    {
        switch (type)
        {
        case Debug::DebugLogMessagesType::All:
            return L"logs.xml";
        case Debug::DebugLogMessagesType::Info:
            return L"info.xml";
        case Debug::DebugLogMessagesType::Debug:
            return L"debug.xml";
        case Debug::DebugLogMessagesType::Error:
            return L"errors.xml";
        default:
            break;
        }
        return L"";
    }

    void Debug::Log(const std::vector<DebugLogMessagesType> messageTypes, std::string_view prefix, std::string_view function, std::string_view text)
    {
        const auto& time = GetTime();
        bool isMessageShowed = false;
        for (const auto& messageType : messageTypes)
        {
            auto& message = _messages.at(messageType)->AddMessage(prefix, time, function, text);

            if (!isMessageShowed)
            {
                std::cout << message.GetString() << std::endl;
                isMessageShowed = true;
            }
        }
    }

    void DebugUtils::Info(std::string_view function, std::string_view text)
    {
        Application::GetSingleton().GetRefContext().GetDebug()->InfoMessage(function, text);
    }

    void DebugUtils::Debug(std::string_view function, std::string_view text)
    {
        Application::GetSingleton().GetRefContext().GetDebug()->DebugMessage(function, text);
    }

    void DebugUtils::Error(std::string_view function, std::string_view text)
    {
        Application::GetSingleton().GetRefContext().GetDebug()->ErrorMessage(function, text);
    }

    void DebugUtils::Assert(bool condition, std::string_view function, std::string_view text)
    {
        if (!condition)
        {
            Error(function, text);
            DebugBreak();
        }
    }

    void DebugUtils::DebugBreak()
    {
        __debugbreak();
    }
}
