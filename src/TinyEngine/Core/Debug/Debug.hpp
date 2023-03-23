#ifndef _DEBUG_HEADER_
#define _DEBUG_HEADER_

#include <TinyEngine/Core/Reflection/ReflectionObject.hpp>
#include <TinyEngine/Core/Reflection/ReflectionMember.hpp>

#include <TinyEngine/Core/Data/String.hpp>

namespace TinyEngine
{
	class DebugLogMessage final : public ReflectionableObject
	{
		REFLECTION_OBJECT_BEGIN(DebugLogMessage)
			REFLECTION_MEMBER("prefix", _prefix)
			REFLECTION_MEMBER("time", _time)
			REFLECTION_MEMBER("text", _text)
		REFLECTION_OBJECT_END

	public:
		DebugLogMessage() = default;
		~DebugLogMessage() = default;

	public:
		void Init(std::string_view prefix, std::string_view time, std::string_view text);

		const std::string& GetPrefix() const { return _prefix; }
		const std::string& GetTime() const { return _time; }
		const std::string& GetText() const { return _text; }

	private:
		std::string _prefix;
		std::string _time;
		std::string _text;
	};

	class DebugLogMessages final : public ReflectionableObject
	{
		REFLECTION_OBJECT_BEGIN(DebugLogMessage)
			REFLECTION_MEMBER("messages", _messages)
		REFLECTION_OBJECT_END

	public:
		DebugLogMessages() = default;
		~DebugLogMessages() = default;

	public:
		void SetFilePath(std::wstring_view filePath);
		void AddMessage(std::string_view prefix, std::string_view time, std::string_view text);

		void Save();

	private:
		std::wstring _filePath;
		std::vector<DebugLogMessage> _messages;
	};

	class Debug final
	{
	public:
		Debug() = default;
		~Debug() = default;

	public:
		void Init();
		void Deinit();

		void Save();

		void InfoMessage(std::string_view text);
		void DebugMessage(std::string_view text);
		void ErrorMessage(std::string_view text);

	private:
		std::string GetTime() const;

	private:
		DebugLogMessages _allMessages;
		DebugLogMessages _infoMessages;
		DebugLogMessages _debugMessages;
		DebugLogMessages _errorMessages;
	};

	class DebugUtils final
	{
	public:
		static void Info(std::string_view text);
		static void Debug(std::string_view text);
		static void Error(std::string_view text);
		static void Assert(bool condition, std::string_view text);

		template<typename T>
		static bool Verify(T* ptr, std::string_view text);

		static void DebugBreak();
	};

	template<typename T>
	bool DebugUtils::Verify(T* ptr, std::string_view text)
	{
		bool isSuccess = ptr != nullptr;
		if (!isSuccess)
		{
			Assert(false, text);
		}
		return isSuccess;
	}
}

#define _DEBUG_MSG(message, ...) TinyEngine::String(std::string{"[{}] "} + message).Params(__FUNCTION__, __VA_ARGS__).Get()
#define DEBUG_INFO(message, ...) TinyEngine::DebugUtils::Info(_DEBUG_MSG(message, __VA_ARGS__))
#define DEBUG_MESSAGE(message, ...) TinyEngine::DebugUtils::Debug(_DEBUG_MSG(message, __VA_ARGS__))
#define DEBUG_ERROR(message, ...) TinyEngine::DebugUtils::Error(_DEBUG_MSG(message, __VA_ARGS__))
#define DEBUG_ASSERT(condition, message, ...) TinyEngine::DebugUtils::Assert(condition, _DEBUG_MSG(message, __VA_ARGS__))
#define DEBUG_VERIFY(expression, message, ...) TinyEngine::DebugUtils::Verify((expression), _DEBUG_MSG(message, __VA_ARGS__))

#endif // _DEBUG_HEADER_
