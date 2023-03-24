#ifndef _DEBUG_HEADER_
#define _DEBUG_HEADER_

#include <TinyEngine/Core/Reflection/ReflectionObject.hpp>
#include <TinyEngine/Core/Reflection/ReflectionMember.hpp>

#include <TinyEngine/Core/Data/String.hpp>

#include <TinyEngine/Core/Events/Signal.hpp>

#include <vector>
#include <map>
#include <memory>

namespace TinyEngine
{
	struct DebugLogShowParams
	{
		bool isShowPrefix = true;
		bool isShowTime = true;
		bool isShowFunction = true;
	};

	class DebugLogMessage final : public ReflectionableObject
	{
		REFLECTION_OBJECT_BEGIN(DebugLogMessage)
			REFLECTION_MEMBER("prefix", _prefix)
			REFLECTION_MEMBER("time", _time)
			REFLECTION_MEMBER("function", _function)
			REFLECTION_MEMBER("text", _text)
		REFLECTION_OBJECT_END

	public:
		DebugLogMessage() = default;
		~DebugLogMessage() = default;

	public:
		void Init(std::string_view prefix, std::string_view time, std::string_view function, std::string_view text);

		const std::string& GetPrefix() const { return _prefix; }
		const std::string& GetTime() const { return _time; }
		const std::string& GetFunction() const { return _function; }
		const std::string& GetText() const { return _text; }

		std::string GetString(const DebugLogShowParams& params) const;

	private:
		std::string _prefix;
		std::string _time;
		std::string _function;
		std::string _text;
	};

	class DebugLogMessages final : public ReflectionableObject
	{
		REFLECTION_OBJECT_BEGIN(DebugLogMessage)
			REFLECTION_MEMBER("messages", _messages)
		REFLECTION_OBJECT_END

	public:
		using MessageAdded = Signal<const DebugLogMessage&>;

	public:
		DebugLogMessages() = default;
		~DebugLogMessages() = default;

	public:
		void SetFilePath(std::wstring_view filePath);
		DebugLogMessage& AddMessage(std::string_view prefix, std::string_view time, std::string_view function, std::string_view text);

		void Save();

		MessageAdded& GetOnMessageAddedSignal() { return _onMessageAddedSignal; }

		const std::vector<DebugLogMessage>& GetMessages() const { return _messages; }

	private:
		void OnMessageAdded(const DebugLogMessage& message);

	private:
		std::wstring _filePath;
		std::vector<DebugLogMessage> _messages;
		MessageAdded _onMessageAddedSignal;
	};

	class Debug final
	{
	public:
		enum class DebugLogMessagesType
		{
			All,
			Info,
			Debug,
			Error
		};

	public:
		Debug() = default;
		~Debug() = default;

	public:
		void Init();
		void Deinit();

		void Save();

		void InfoMessage(std::string_view function, std::string_view text);
		void DebugMessage(std::string_view function, std::string_view text);
		void ErrorMessage(std::string_view function, std::string_view text);

		DebugLogMessages* GetDebugLogMessages(DebugLogMessagesType type) const;

	private:
		std::string GetTime() const;
		std::wstring GetFilePathByMessagesType(DebugLogMessagesType type) const;

		void Log(const std::vector<DebugLogMessagesType> messageTypes, std::string_view prefix, std::string_view function, std::string_view text);

	private:
		std::map<DebugLogMessagesType, std::unique_ptr<DebugLogMessages>> _messages;
	};

	class DebugUtils final
	{
	public:
		static void Info(std::string_view function, std::string_view text);
		static void Debug(std::string_view function, std::string_view text);
		static void Error(std::string_view function, std::string_view text);
		static void Assert(bool condition, std::string_view function, std::string_view text);

		template<typename T>
		static bool Verify(T* ptr, std::string_view function, std::string_view text);

		static void DebugBreak();
	};

	template<typename T>
	bool DebugUtils::Verify(T* ptr, std::string_view function, std::string_view text)
	{
		bool isSuccess = ptr != nullptr;
		if (!isSuccess)
		{
			Assert(false, function, text);
		}
		return isSuccess;
	}
}

#define _DEBUG_MSG(message, ...) TinyEngine::String(message).Params(__VA_ARGS__).Get()
#define DEBUG_INFO(message, ...) TinyEngine::DebugUtils::Info(__FUNCTION__, _DEBUG_MSG(message, __VA_ARGS__))
#define DEBUG_MESSAGE(message, ...) TinyEngine::DebugUtils::Debug(__FUNCTION__, _DEBUG_MSG(message, __VA_ARGS__))
#define DEBUG_ERROR(message, ...) TinyEngine::DebugUtils::Error(__FUNCTION__, _DEBUG_MSG(message, __VA_ARGS__))
#define DEBUG_ASSERT(condition, message, ...) TinyEngine::DebugUtils::Assert(condition, __FUNCTION__, _DEBUG_MSG(message, __VA_ARGS__))
#define DEBUG_VERIFY(expression, message, ...) TinyEngine::DebugUtils::Verify((expression), __FUNCTION__, _DEBUG_MSG(message, __VA_ARGS__))

#endif // _DEBUG_HEADER_
