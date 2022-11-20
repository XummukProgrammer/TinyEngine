#include "ConditionContext.hpp"

#include <TinyEngine/Core/Conditions/ConditionVariable.hpp>

namespace TinyEngine
{
	void ConditionContext::AddVariable(std::string_view id, BaseConditionVariableSharedPtr variable)
	{
		_variables[std::string{id}] = variable;
	}

	bool ConditionContext::HasVariable(std::string_view id) const
	{
		return GetVariable(id) != nullptr;
	}

	BaseConditionVariableSharedPtr ConditionContext::GetVariable(std::string_view id) const
	{
		auto it = _variables.find(std::string{id});
		if (it != _variables.end())
		{
			return it->second;
		}
		return nullptr;
	}
}
