#include "Logger.hpp"

#include <TinyEngine/../../stacktrace/stacktrace.hpp>

namespace TinyEngine
{
	void LoggerMessage::Init(LogType type, std::string_view message)
	{
		_type = type;
		_message = message;
	}

	void LoggerMessages::AddMessage(const LoggerMessage& message)
	{
		_messages.push_back(message);
	}

	std::vector<std::string> LoggerMessages::GetMessagesFromType(LogType type) const
	{
		std::vector<std::string> messages;
		const int intType = static_cast<int>(type);

		for (const auto& message : _messages)
		{
			if (static_cast<int>(message.GetType()) & intType)
			{
				messages.push_back(message.GetMsg());
			}
		}

		return messages;
	}

	void Logger::SaveToFile()
	{
		SerializationUtils::SaveRootToFile(ArchiveFormat::Xml, "../_logs/logs.xml", &_messages);
	}

	void Logger::PrintMessage(LogType type, std::string_view message)
	{
		LoggerMessage loggerMessage;
		loggerMessage.Init(type, message);

		fmt::print("{}\n", loggerMessage.GetMsg());

		_messages.AddMessage(loggerMessage);
	}

	std::vector<std::string> Logger::GetMessagesFromType(LogType type) const
	{
		return _messages.GetMessagesFromType(type);
	}
}
