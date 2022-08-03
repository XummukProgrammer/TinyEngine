#ifndef _LOGGER_HEADER_
#define _LOGGER_HEADER_

#include <TinyEngine/Data/Singleton.hpp>

#include <TinyEngine/Data/Serialization/SerializationVisitor.hpp>

namespace TinyEngine
{
	class LoggerStacktrace final : public ISerializable
	{
		TINY_ENGINE_SER_BEGIN(LoggerStacktrace)
		{
			TINY_ENGINE_SER_FIELD(_stacktrace)
		}
		TINY_ENGINE_SER_END

	public:
		LoggerStacktrace() = default;
		~LoggerStacktrace() = default;

	public:
		void Init(std::string_view stacktrace);

	private:
		std::string _stacktrace;
	};

	class LoggerMessage final : public ISerializable
	{
		TINY_ENGINE_SER_BEGIN(LoggerMessage)
		{
			TINY_ENGINE_SER_FIELD(_type)
			TINY_ENGINE_SER_FIELD(_time)
			TINY_ENGINE_SER_FIELD(_sender)
			TINY_ENGINE_SER_FIELD(_message)
			TINY_ENGINE_SER_FIELD(_stacktrace)
		}
		TINY_ENGINE_SER_END

	public:
		LoggerMessage() = default;
		~LoggerMessage() = default;

	public:
		void Init(std::string_view type, std::string_view time, std::string_view sender, std::string_view message, std::string_view stacktrace);

	private:
		std::string _type;
		std::string _time;
		std::string _sender;
		std::string _message;
		LoggerStacktrace _stacktrace;
	};

	class LoggerMessages final : public ISerializable
	{
		TINY_ENGINE_SER_BEGIN(LoggerMessages)
		{
			TINY_ENGINE_SER_FIELD(_messages)
		}
		TINY_ENGINE_SER_END

	public:
		LoggerMessages() = default;
		~LoggerMessages() = default;

	public:
		void AddMessage(const LoggerMessage& message);

	private:
		std::vector<LoggerMessage> _messages;
	};

	class Logger final : public Singleton<Logger>
	{
	public:
		Logger() = default;
		~Logger() = default;
	
	public:
		void SaveToFile();

		void PrintMessage(std::string_view type, std::string_view sender, std::string_view message, bool isShowStacktrace);

	private:
		LoggerMessages _messages;
	};
}

#define TINY_ENGINE_PRINT_MESSAGE(type, message, isShowStacktrace) TinyEngine::Logger::GetInstance().PrintMessage(type, __FUNCTION__, message, isShowStacktrace)
#define TINY_ENGINE_PRINT_INFO(message) TINY_ENGINE_PRINT_MESSAGE("info", message, false)

#endif // _LOGGER_HEADER_
