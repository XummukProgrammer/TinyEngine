#include "Assert.hpp"

#include <intrin.h>

namespace TE
{

CAssert::CAssert(bool conditionResult)
	: _conditionResult(conditionResult)
{ 
}

void CAssert::setOnBreakpoinedCallback(const BreakpointedCallback& callback)
{ 
	_onBreakpointedCallback = callback;
}

void CAssert::setBreakpointLoop(bool isLoop)
{
	_isBreakpointLoop = isLoop;
}

void CAssert::breakpoint()
{ 
	__debugbreak();
}

bool CAssert::getConditionResult() const
{
	return _conditionResult;
}

void CAssert::tryRun()
{ 
	if (!_conditionResult) {
		if (_onBreakpointedCallback) {
			_onBreakpointedCallback();
		}

		do {
			breakpoint();
		}
		while (_isBreakpointLoop);
	}
}

}
