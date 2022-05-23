#ifndef _TINY_ENGINE_DEBUG_ADAPTER_HEADER_
#define _TINY_ENGINE_DEBUG_ADAPTER_HEADER_

#include "DebugMessage.hpp"
#include "Log.hpp"
#include "Assert.hpp"

#include <TinyEngine/Core/Paths.hpp>

namespace TE
{

class CDebugAdapter final
{
public:
	CDebugAdapter(CPaths& paths, CLog& log);
	~CDebugAdapter() = default;

public:
	void sendInfoMessage(const std::string& message);
	void sendErrorMessage(const std::string& message);
	void sendCriticalMessage(const std::string& message);

	void assert(bool conditionResult, const std::string& message);

	template<typename T>
	bool verify(T* ptr, const std::string& message);

private:
	CPaths& _paths;
	CLog& _log;
};

template<typename T>
bool CDebugAdapter::verify(T* ptr, const std::string& message)
{
	bool conditionResult = ptr != nullptr;
	auto verifyAssert = CAssert(conditionResult);
	verifyAssert.setBreakpointLoop(true);
	verifyAssert.setOnBreakpoinedCallback([this, message]() {
		_log.addLogMessage({ CDebugMessage::Type::Verify, message });
		_log.dumpAllLogMessages(_paths);
	});
	verifyAssert.tryRun();
	return conditionResult;
}

}

#endif // _TINY_ENGINE_DEBUG_ADAPTER_HEADER_
