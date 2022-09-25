#include "Logger.hpp"

#include <fmt/format.h>
#include <TinyEngine/../../stacktrace/stacktrace.hpp>

namespace TinyEngine
{
	void LoggerMessage::Init(std::string_view type, std::string_view time, std::string_view sender, std::string_view message, std::string_view stacktrace)
	{
		_type = type;
		_time = time;
		_sender = sender;
		_message = message;
	}

	void LoggerMessages::AddMessage(const LoggerMessage& message)
	{
		_messages.push_back(message);
	}

	void Logger::SaveToFile()
	{
		SerializationUtils::SaveRootToFile(ArchiveFormat::Xml, "../_logs/logs.xml", &_messages);
	}

	void Logger::PrintMessage(std::string_view type, std::string_view sender, std::string_view message, bool isShowStacktrace)
	{
		const std::string time = "12.12.2099 23:59:59";
		std::string stacktrace;

		fmt::print("[{}][{}][{}] {}\n", type, time, sender, message);

		if (isShowStacktrace)
		{
			stacktrace = markusjx::stacktrace::stacktrace().toString();
			fmt::print("\n\nStacktrace:\n{}\n\n", stacktrace);
		}

		LoggerMessage loggerMessage;
		loggerMessage.Init(type, time, sender, message, stacktrace);

		_messages.AddMessage(loggerMessage);
	}
}
