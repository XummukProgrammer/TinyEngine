#ifndef _DEBUG_HEADER_
#define _DEBUG_HEADER_

#include <TinyEngine/Core/Data/Singleton.hpp>

#include <TinyEngine/Core/Constants.hpp>

#include <string>

#define ASSERT_ENABLE

namespace TinyEngine
{
	class IDebugOperation
	{
	public:
		IDebugOperation(std::string_view message, bool isActive)
			: _message(message), _isActive(isActive)
		{
		}
		virtual ~IDebugOperation() = default;

	public:
		virtual bool IsEnable() const { return true; }
		virtual bool IsActive() const = 0;
		virtual bool IsShowStacktrace() const = 0;
		virtual bool IsStopProgram() const = 0;
		virtual bool IsLoggerDumpToFile() const { return IsStopProgram(); }

		virtual LogType GetLoggerMessageType() const = 0;

	public:
		const std::string& GetMessage() const { return _message; }

	protected:
		bool _isActive = false;

	private:
		std::string _message;
	};

	class DebugAssertOperation : public IDebugOperation
	{
	public:
		DebugAssertOperation(std::string_view message, bool isActive)
			: IDebugOperation(message, isActive)
		{
		}
		~DebugAssertOperation() = default;

	public:
		virtual bool IsEnable() const
		{
#ifdef ASSERT_ENABLE
			return true;
#endif
			return false;
		}
		bool IsActive() const override { return !_isActive; }
		bool IsShowStacktrace() const override { return true; }
		bool IsStopProgram() const override { return true; }

		LogType GetLoggerMessageType() const override { return LogType::Assert; }
	};

	class DebugVerifyOperation : public IDebugOperation
	{
	public:
		DebugVerifyOperation(std::string_view message, bool isActive)
			: IDebugOperation(message, isActive)
		{
		}
		~DebugVerifyOperation() = default;

	public:
		bool IsActive() const override { return !_isActive; }
		bool IsShowStacktrace() const override { return true; }
		bool IsStopProgram() const override { return false; }

		LogType GetLoggerMessageType() const override { return LogType::Verify; }
	};

	class DebugCriticalOperation : public IDebugOperation
	{
	public:
		DebugCriticalOperation(std::string_view message, bool isActive)
			: IDebugOperation(message, isActive)
		{
		}
		~DebugCriticalOperation() = default;

	public:
		bool IsActive() const override { return !_isActive; }
		bool IsShowStacktrace() const override { return true; }
		bool IsStopProgram() const override { return true; }

		LogType GetLoggerMessageType() const override { return LogType::Critical; }
	};

	class Debug final : public Singleton<Debug>
	{
	public:
		Debug() = default;
		~Debug() = default;

	public:
		bool OperationProcess(std::string_view sender, IDebugOperation& debugOperation);

	private:
		void StopProgram();
	};
}

#define TINY_ENGINE_ASSERT(condition, message) TinyEngine::Debug::GetInstance()->OperationProcess(__FUNCTION__, TinyEngine::DebugAssertOperation(message, condition))
#define TINY_ENGINE_VERIFY(ptr, message) !TinyEngine::Debug::GetInstance()->OperationProcess(__FUNCTION__, TinyEngine::DebugVerifyOperation(message, (ptr)))
#define TINY_ENGINE_CRITICAL(condition, message) TinyEngine::Debug::GetInstance()->OperationProcess(__FUNCTION__, TinyEngine::DebugCriticalOperation(message, condition))

#endif // _DEBUG_HEADER_
