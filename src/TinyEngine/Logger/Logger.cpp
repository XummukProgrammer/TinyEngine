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
			messageNode.append_attribute("type").set_value(loggerMessage->type.c_str());
			messageNode.append_attribute("time").set_value(loggerMessage->time.c_str());
			messageNode.append_attribute("sender").set_value(loggerMessage->sender.c_str());
			messageNode.append_attribute("message").set_value(loggerMessage->message.c_str());

			if (!loggerMessage->stacktrace.empty())
			{
				auto stacktraceNode = messageNode.append_child("stacktrace");

				for (const auto& stacktraceMessage : loggerMessage->stacktrace)
				{
					auto stacktraceMessageNode = stacktraceNode.append_child("message");
					stacktraceMessageNode.append_attribute("text").set_value(stacktraceMessage.c_str());
				}
			}
		}

		doc.save_file(fileName.data());
	}

	void Logger::MessagePrintToConsole(std::string_view type, std::string_view sender, std::string_view message, bool isShowStacktrace)
	{
		auto loggerMessage = AddMessage(type, sender, message, isShowStacktrace);

		fmt::print("[{}][{}] [{}] {}\n", loggerMessage->type, loggerMessage->time, loggerMessage->sender, loggerMessage->message);

		if (isShowStacktrace && !loggerMessage->stacktrace.empty())
		{
			fmt::print("Stacktrace:\n");

			for (const auto& stacktraceMessage : loggerMessage->stacktrace)
			{
				fmt::print("    {}", stacktraceMessage);
			}
		}
	}

	void Logger::DumpToFile(std::string_view fileName, IDumpFormat& dumpFormat)
	{
		dumpFormat.DumpToFile(fileName, _messages);
	}

	LoggerMessage::Ptr Logger::AddMessage(std::string_view type, std::string_view sender, std::string_view message, bool isShowStacktrace)
	{
		std::string time;
		std::list<std::string> stacktrace;
		auto loggerMessage = LoggerMessage::Create(type, time, sender, message, stacktrace);
		_messages.push_back(loggerMessage);
		return loggerMessage;
	}
}
