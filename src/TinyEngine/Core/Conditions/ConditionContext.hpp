#ifndef _CONDITION_CONTEXT_HEADER_
#define _CONDITION_CONTEXT_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <map>
#include <string>

namespace TinyEngine
{
	class ConditionContext final
	{
	public:
		ConditionContext() = default;
		~ConditionContext() = default;

	public:
		void AddVariable(std::string_view id, IConditionVariableSharedPtr variable);
		bool HasVariable(std::string_view id) const;
		IConditionVariableSharedPtr GetVariable(std::string_view id) const;

	private:
		std::map<std::string, IConditionVariableSharedPtr> _variables;
	};
}

#endif // _CONDITION_CONTEXT_HEADER_
