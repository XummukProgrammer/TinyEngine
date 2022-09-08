#ifndef _LOGGER_HEADER_
#define _LOGGER_HEADER_

#include <TinyEngine/Data/Singleton.hpp>

#include <TinyEngine/Data/Serialization/SerializationDefines.hpp>
#include <TinyEngine/Data/Meta/MetaDefines.hpp>

namespace TinyEngine
{
	class LoggerStacktrace final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(LoggerStacktrace)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_stacktrace, "Stacktrace", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		LoggerStacktrace() = default;
		~LoggerStacktrace() = default;

	public:
		void Init(std::string_view stacktrace);

	private:
		std::string _stacktrace;
	};

	class LoggerMessage final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(LoggerMessage)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_type, "Type", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_time, "Time", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_sender, "Sender", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_message, "Message", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_stacktrace, "Stacktrace", "");
		}
		TINY_ENGINE_META_CLASS_END

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

	class LoggerMessages final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(LoggerMessages)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_messages, "Messages", "");
		}
		TINY_ENGINE_META_CLASS_END

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

#define TINY_ENGINE_PRINT_MESSAGE(type, message, isShowStacktrace) TinyEngine::Logger::GetInstance()->PrintMessage(type, __FUNCTION__, message, isShowStacktrace)
#define TINY_ENGINE_PRINT_INFO(message) TINY_ENGINE_PRINT_MESSAGE("info", message, false)

#endif // _LOGGER_HEADER_
