#include "DebugAdapter.hpp"

namespace TE
{

CDebugAdapter::CDebugAdapter(CPaths& paths, CLog& log)
	: _paths(paths)
	, _log(log)
{ 
}

void CDebugAdapter::sendInfoMessage(const std::string& message)
{ 
	_log.addLogMessage({ CDebugMessage::Type::Info, message });
}

void CDebugAdapter::sendErrorMessage(const std::string& message)
{ 
	_log.addLogMessage({ CDebugMessage::Type::Error, message });

	auto errorAssert = CAssert(false);
	errorAssert.tryRun();
}

void CDebugAdapter::sendCriticalMessage(const std::string& message)
{
	_log.addLogMessage({ CDebugMessage::Type::Critical, message });

	auto criticalAssert = CAssert(false);
	criticalAssert.setBreakpointLoop(true);
	criticalAssert.setOnBreakpoinedCallback([this]() {
		_log.dumpAllLogMessages(_paths);
	});
	criticalAssert.tryRun();
}

void CDebugAdapter::assert(bool conditionResult, const std::string& message)
{ 
	auto assertObj = CAssert(conditionResult);
	assertObj.setOnBreakpoinedCallback([this, message]() {
		_log.addLogMessage({ CDebugMessage::Type::Assert, message });
	});
	assertObj.tryRun();
}

}
