#ifndef _LOGGER_HEADER_
#define _LOGGER_HEADER_

#include <list>
#include <memory>
#include <string>

namespace TinyEngine
{
	struct LoggerMessage
	{
		using Ptr = std::shared_ptr<LoggerMessage>;

		std::string type;
		std::string time;
		std::string sender;
		std::string message;
		std::list<std::string> stacktrace;

		LoggerMessage(std::string_view type, std::string_view time, std::string_view sender, std::string_view message, const std::list<std::string>& stacktrace)
			: type(type), time(time), sender(sender), message(message), stacktrace(stacktrace)
		{}

		static Ptr Create(std::string_view type, std::string_view time, std::string_view sender, std::string_view message, const std::list<std::string>& stacktrace) 
		{ 
			return std::make_shared<LoggerMessage>(type, time, sender, message, stacktrace);
		}
	};

	using LoggerMessages = std::list<LoggerMessage::Ptr>;

	class IDumpFormat
	{
	public:
		IDumpFormat() = default;
		virtual ~IDumpFormat() = default;

	public:
		virtual void DumpToFile(std::string_view fileName, const LoggerMessages& loggerMessages) = 0;
	};

	class IDumpXmlFormat final : public IDumpFormat
	{
	public:
		IDumpXmlFormat() = default;
		~IDumpXmlFormat() = default;

	public:
		void DumpToFile(std::string_view fileName, const LoggerMessages& loggerMessages) override;
	};

	class Logger final
	{
	public:
		Logger() = default;
		~Logger() = default;

	public:
		void MessagePrintToConsole(std::string_view type, std::string_view sender, std::string_view message, bool isShowStacktrace);

		void DumpToFile(std::string_view fileName, IDumpFormat& dumpFormat);

	private:
		LoggerMessage::Ptr AddMessage(std::string_view type, std::string_view sender, std::string_view message, bool isShowStacktrace);

	private:
		LoggerMessages _messages;
	};

	extern Logger logger;
}

#define TINY_ENGINE_PRINT_TO_CONSOLE(type, message, isShowStacktrace) TinyEngine::logger.MessagePrintToConsole(type, __FUNCTION__, message, isShowStacktrace)

#endif // _LOGGER_HEADER_
