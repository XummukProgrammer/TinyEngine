#include "Log.hpp"

#include <pugixml.hpp>

namespace TE
{

void CLog::setFileName(Type type, const std::string& fileName)
{ 
    _fileNames[type] = fileName;
}

const std::string& CLog::getFileName(Type type) const
{
    return _fileNames.at(type);
}

void CLog::addLogMessage(Type type, const std::string& message)
{ 
    _messages[type].push_back(message);
}

void CLog::dumpLogMessages(const CPaths& paths, Type type) const
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
        messageAttribute.set_value(message.c_str());
    }

    doc.save_file(path.c_str());
}

void CLog::dumpAllLogMessages(const CPaths& paths) const
{ 
    dumpLogMessages(paths, Type::Info);
    dumpLogMessages(paths, Type::Error);
    dumpLogMessages(paths, Type::Critical);
}

}
