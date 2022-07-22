﻿#include "Debug.hpp"

#include <TinyEngine/Logger/Logger.hpp>

namespace TinyEngine
{
	Debug debug;

	bool Debug::OperationProcess(std::string_view sender, IDebugOperation& debugOperation)
	{
		if (debugOperation.IsActive())
		{
			logger.MessagePrintToConsole(debugOperation.GetLoggerMessageType(), sender, debugOperation.GetMessage(), debugOperation.IsShowStacktrace());

			if (debugOperation.IsLoggerDumpToFile())
			{
				logger.DumpToFile("dump.xml", DumpXmlFormat());
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
