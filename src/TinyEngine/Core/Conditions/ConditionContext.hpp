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
		void AddVariable(std::string_view id, BaseConditionVariableSharedPtr variable);
		bool HasVariable(std::string_view id) const;
		BaseConditionVariableSharedPtr GetBaseVariable(std::string_view id) const;
		template<typename T> std::shared_ptr<T> GetVariable(std::string_view id) const;

	private:
		std::map<std::string, BaseConditionVariableSharedPtr> _variables;
	};

	template<typename T>
	std::shared_ptr<T> ConditionContext::GetVariable(std::string_view id) const
	{
		if (auto variable = GetBaseVariable(id))
		{
			return std::dynamic_pointer_cast<T>(variable);
		}
		return nullptr;
	}
}

#endif // _CONDITION_CONTEXT_HEADER_
