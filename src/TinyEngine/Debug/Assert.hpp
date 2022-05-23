#ifndef _TINY_ENGINE_ASSERT_HEADER_
#define _TINY_ENGINE_ASSERT_HEADER_

#include <functional>

namespace TE
{

class CAssert final
{
public:
	using BreakpointedCallback = std::function<void()>;

public:
	CAssert(bool conditionResult);
	~CAssert() = default;

public:
	void setOnBreakpoinedCallback(const BreakpointedCallback& callback);
	void setBreakpointLoop(bool isLoop);
	void breakpoint();

	bool getConditionResult() const;

	void tryRun();

private:
	bool _conditionResult = true;
	std::function<void()> _onBreakpointedCallback;
	bool _isBreakpointLoop = false;
};

}

#endif // _TINY_ENGINE_ASSERT_HEADER_
