﻿#include "Logger.hpp"

#include <boost/stacktrace.hpp>

#include <fmt/format.h>

namespace TinyEngine
{
	void LoggerMessage::Init(std::string_view type, std::string_view time, std::string_view sender, std::string_view message, std::string_view stacktrace)
	{
		_type = type;
		_time = time;
		_sender = sender;
		_message = message;
		_stacktrace.Init(stacktrace);
	}

	void LoggerStacktrace::Init(std::string_view stacktrace)
	{
		_stacktrace = stacktrace;
	}

	void LoggerMessages::AddMessage(const LoggerMessage& message)
	{
		_messages.push_back(message);
	}

	void Logger::SaveToFile()
	{
		SerializationUtils::SaveRootToFile(SerializationUtils::ArchiveFormat::Xml, "../_logs/logs.xml", &_messages);
	}

	void Logger::PrintMessage(std::string_view type, std::string_view sender, std::string_view message, bool isShowStacktrace)
	{
		const std::string time = "12.12.2099 23:59:59";
		std::string stacktrace;

		fmt::print("[{}][{}][{}] {}\n", type, time, sender, message);

		if (isShowStacktrace)
		{
			stacktrace = boost::stacktrace::to_string(boost::stacktrace::stacktrace());
			fmt::print("\n\nStacktrace:\n{}\n\n", stacktrace);
		}

		LoggerMessage loggerMessage;
		loggerMessage.Init(type, time, sender, message, stacktrace);

		_messages.AddMessage(loggerMessage);
	}
}
