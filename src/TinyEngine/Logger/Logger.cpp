#include "Logger.hpp"

#include <fmt/format.h>
#include <pugixml.hpp>

namespace TinyEngine
{
	Logger logger;

	void IDumpXmlFormat::DumpToFile(std::string_view fileName, const LoggerMessages& loggerMessages)
	{
		pugi::xml_document doc;

		auto rootNode = doc.append_child("root");

		for (const auto& loggerMessage : loggerMessages)
		{
			auto messageNode = rootNode.append_child("message");
			messageNode.append_attribute("time").set_value(loggerMessage->time.c_str());
			messageNode.append_attribute("receiver").set_value(loggerMessage->receiver.c_str());
			messageNode.append_attribute("message").set_value(loggerMessage->message.c_str());
		}

		doc.save_file(fileName.data());
	}

	void Logger::MessagePrintToConsole(std::string_view receiver, std::string_view message)
	{
		auto loggerMessage = AddMessage(receiver, message);

		fmt::print("[{}] [{}] {}", loggerMessage->time, loggerMessage->receiver, loggerMessage->message);
	}

	void Logger::DumpToFile(std::string_view fileName, IDumpFormat* dumpFormat)
	{
		if (!dumpFormat)
		{
			return;
		}

		dumpFormat->DumpToFile(fileName, _messages);
	}

	LoggerMessage::Ptr Logger::AddMessage(std::string_view receiver, std::string_view message)
	{
		auto loggerMessage = LoggerMessage::Create("", receiver, message);
		_messages.push_back(loggerMessage);
		return loggerMessage;
	}
}
