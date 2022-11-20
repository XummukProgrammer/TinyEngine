#include "ConditionVariable.hpp"

#include <TinyEngine/Core/Conditions/ConditionContext.hpp>

namespace TinyEngine
{
	void BaseConditionVariable::SetLocalContext(ConditionContextPtr context)
	{
		_localContext = context;
	}

	ConditionContextPtr BaseConditionVariable::GetLocalContext() const
	{
		return _localContext;
	}
}
