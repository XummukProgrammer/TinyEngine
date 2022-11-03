#ifndef _LOGGER_HEADER_
#define _LOGGER_HEADER_

#include <TinyEngine/Core/Data/Singleton.hpp>

#include <TinyEngine/Core/Data/Serialization/SerializationDefines.hpp>
#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

#include <TinyEngine/Core/Constants.hpp>

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
		void PrintInfo(std::string_view message) { PrintMessage(LogType::Info, message); }
		void PrintAssert(std::string_view message) { PrintMessage(LogType::Assert, message); }
		void PrintVerify(std::string_view message) { PrintMessage(LogType::Verify, message); }
		void PrintCritical(std::string_view message) { PrintMessage(LogType::Critical, message); }

		std::vector<std::string> GetMessagesFromType(LogType type) const;

	private:
		LoggerMessages _messages;
	};
}


#endif // _LOGGER_HEADER_
