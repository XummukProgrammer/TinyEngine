#include "Log.hpp"

#include <pugixml.hpp>
#include <fmt/format.h>

#include <iostream>

namespace TE
{

void CLog::setFileName(CDebugMessage::Type type, const std::string& fileName)
{ 
    _fileNames[type] = fileName;
}

const std::string& CLog::getFileName(CDebugMessage::Type type) const
{
    return _fileNames.at(type);
}

void CLog::addLogMessage(const CDebugMessage& debugMessage)
{ 
    _messages[debugMessage.getType()].push_back(debugMessage);

    printLogMessageToConsole(debugMessage);
}

void CLog::dumpLogMessages(const CPaths& paths, CDebugMessage::Type type) const
{ 
    const auto& fileName = getFileName(type);
    auto&& path = paths.buildPath(CPaths::Type::Logs, fileName);

    auto listMessagesIt = _messages.find(type);
    if (listMessagesIt == _messages.end()) {
        return;
    }

    const auto& listMessages = listMessagesIt->second;

    pugi::xml_document doc;
    auto messagesNode = doc.append_child("messages");

    for (const auto& message : listMessages) {
        auto messageNode = messagesNode.append_child("message");
        auto messageAttribute = messageNode.append_attribute("text");
        messageAttribute.set_value(message.getMessage().c_str());
    }

    doc.save_file(path.c_str());
}

void CLog::dumpAllLogMessages(const CPaths& paths) const
{ 
    for (const auto& [type, messages] : _messages) {
        dumpLogMessages(paths, type);
    }
}

void CLog::printLogMessageToConsole(const CDebugMessage& debugMessage)
{
    fmt::print("[{}] {}\n", 
        CDebugMessage::typeToString(debugMessage.getType()), 
        debugMessage.getMessage());   
}

}
