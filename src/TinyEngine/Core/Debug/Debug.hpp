#ifndef _DEBUG_HEADER_
#define _DEBUG_HEADER_

#include <TinyEngine/Core/Reflection/ReflectionObject.hpp>
#include <TinyEngine/Core/Reflection/ReflectionMember.hpp>

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
}

#endif // _DEBUG_HEADER_
