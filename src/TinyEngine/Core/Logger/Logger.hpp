#ifndef _LOGGER_HEADER_
#define _LOGGER_HEADER_

#include <TinyEngine/Data/Singleton.hpp>

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
		std::string stacktrace;

		LoggerMessage(std::string_view type, std::string_view time, std::string_view sender, std::string_view message, std::string_view stacktrace)
			: type(type), time(time), sender(sender), message(message), stacktrace(stacktrace)
		{}

		static Ptr Create(std::string_view type, std::string_view time, std::string_view sender, std::string_view message, std::string_view stacktrace) 
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

	class DumpXmlFormat final : public IDumpFormat
	{
	public:
		DumpXmlFormat() = default;
		~DumpXmlFormat() = default;

	public:
		void DumpToFile(std::string_view fileName, const LoggerMessages& loggerMessages) override;
	};

	class Logger final : public Singleton<Logger>
	{
	public:
		Logger() = default;
		~Logger() = default;

	public:
		void MessagePrintToConsole(std::string_view type, std::string_view sender, std::string_view message, bool isShowStacktrace);

		void DumpToFile(std::string_view fileName, IDumpFormat& dumpFormat);

	private:
		LoggerMessage::Ptr AddMessage(std::string_view type, std::string_view sender, std::string_view message, bool isShowStacktrace);
		std::string ExtractStacktrace() const;

	private:
		LoggerMessages _messages;
	};
}

#define TINY_ENGINE_PRINT_TO_CONSOLE(type, message, isShowStacktrace) TinyEngine::Logger::GetInstance().MessagePrintToConsole(type, __FUNCTION__, message, isShowStacktrace)
#define TINY_ENGINE_INFO(message) TINY_ENGINE_PRINT_TO_CONSOLE("info", message, false)

#endif // _LOGGER_HEADER_
