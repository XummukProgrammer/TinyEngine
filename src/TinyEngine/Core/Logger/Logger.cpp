#include "Logger.hpp"

#include <fmt/format.h>
#include <pugixml.hpp>

#include <boost/stacktrace.hpp>

#include <iostream>

namespace TinyEngine
{
	void DumpXmlFormat::DumpToFile(std::string_view fileName, const LoggerMessages& loggerMessages)
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
				stacktraceNode.text().set(loggerMessage->stacktrace.c_str());
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
			fmt::print("\nStacktrace:\n{}\n", loggerMessage->stacktrace);
		}
	}

	void Logger::DumpToFile(std::string_view fileName, IDumpFormat& dumpFormat)
	{
		dumpFormat.DumpToFile(fileName, _messages);
	}

	LoggerMessage::Ptr Logger::AddMessage(std::string_view type, std::string_view sender, std::string_view message, bool isShowStacktrace)
	{
		std::string time;
		std::string stacktrace;

		if (isShowStacktrace)
		{
			stacktrace = std::move(ExtractStacktrace());
		}

		auto loggerMessage = LoggerMessage::Create(type, time, sender, message, stacktrace);
		_messages.push_back(loggerMessage);
		return loggerMessage;
	}

	std::string Logger::ExtractStacktrace() const
	{
		const auto stacktraceString = boost::stacktrace::to_string(boost::stacktrace::stacktrace());
		return stacktraceString;
	}
}
