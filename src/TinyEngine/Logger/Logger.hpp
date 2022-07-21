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

		std::string time;
		std::string receiver;
		std::string message;

		LoggerMessage(std::string_view time, std::string_view receiver, std::string_view message)
			: time(time), receiver(receiver), message(message)
		{}

		static Ptr Create(std::string_view time, std::string_view receiver, std::string_view message) 
		{ 
			return std::make_shared<LoggerMessage>(time, receiver, message);
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
		void MessagePrintToConsole(std::string_view receiver, std::string_view message);

		void DumpToFile(std::string_view fileName, IDumpFormat* dumpFormat);

	private:
		LoggerMessage::Ptr AddMessage(std::string_view receiver, std::string_view message);

	private:
		LoggerMessages _messages;
	};

	extern Logger logger;
}

#define TINY_ENGINE_PRINT_TO_CONSOLE(message) TinyEngine::logger.MessagePrintToConsole(__FUNCTION__, message)

#endif // _LOGGER_HEADER_
