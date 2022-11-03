#ifndef _LOGGER_HEADER_
#define _LOGGER_HEADER_

#include <TinyEngine/Core/Data/Singleton.hpp>

#include <TinyEngine/Core/Data/Serialization/SerializationDefines.hpp>
#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

#include <TinyEngine/Core/Constants.hpp>

#include <fmt/format.h>

namespace TinyEngine
{
	class LoggerMessage final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(LoggerMessage)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_type, "Type", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_message, "Message", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		LoggerMessage() = default;
		~LoggerMessage() = default;

	public:
		void Init(LogType type, std::string_view message);

		LogType GetType() const { return _type; }
		const std::string& GetMsg() const { return _message; }

	private:
		LogType _type;
		std::string _message;
	};

	class LoggerMessages final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(LoggerMessages)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_messages, "Messages", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		LoggerMessages() = default;
		~LoggerMessages() = default;

	public:
		void AddMessage(const LoggerMessage& message);

		std::vector<std::string> GetMessagesFromType(LogType type) const;

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

		void PrintMessage(LogType type, std::string_view message);
		
		template<typename ... Args>
		void PrintMessageFormat(LogType type, std::string_view message, Args&&... args) { PrintMessage(type, fmt::format(message, std::forward<Args>(args)...)); }

		template<typename ... Args>
		void PrintInfo(std::string_view message, Args&&... args) { PrintMessageFormat(LogType::Info, message, std::forward<Args>(args)...); }

		template<typename ... Args>
		void PrintAssert(std::string_view message, Args&&... args) { PrintMessageFormat(LogType::Assert, message, std::forward<Args>(args)...); }

		template<typename ... Args>
		void PrintError(std::string_view message, Args&&... args) { PrintMessageFormat(LogType::Critical, message, std::forward<Args>(args)...); }

		std::vector<std::string> GetMessagesFromType(LogType type) const;

	private:
		LoggerMessages _messages;
	};
}

#define TINY_ENGINE_INFO(tag, message, ...) Logger::GetInstance()->PrintInfo(std::string{"["} + tag + "] " + message, __VA_ARGS__)

#endif // _LOGGER_HEADER_
