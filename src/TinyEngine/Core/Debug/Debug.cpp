#include "Debug.hpp"

#include <TinyEngine/Core/Application.hpp>
#include <TinyEngine/Core/Logger/Logger.hpp>

namespace TinyEngine
{
	bool Debug::OperationProcess(std::string_view sender, IDebugOperation& debugOperation)
	{
		if (debugOperation.IsActive())
		{
			Logger::GetInstance().MessagePrintToConsole(debugOperation.GetLoggerMessageType(), sender, debugOperation.GetMessage(), debugOperation.IsShowStacktrace());

			if (debugOperation.IsLoggerDumpToFile())
			{
				Application::GetInstance().LoggerDumpToFile();
			}

			if (debugOperation.IsStopProgram())
			{
				StopProgram();
			}

			return true;
		}

		return false;
	}

	void Debug::StopProgram()
	{
#ifdef WIN32
		__debugbreak();
#endif
	}
}
