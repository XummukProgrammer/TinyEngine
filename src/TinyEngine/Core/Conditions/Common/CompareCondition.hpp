#ifndef _COMPARE_CONDITION_HEADER_
#define _COMPARE_CONDITION_HEADER_

#include <TinyEngine/Core/Conditions/Condition.hpp>
#include <TinyEngine/Core/Constants.hpp>
#include <TinyEngine/Core/Conditions/ConditionVariable.hpp>

namespace TinyEngine
{
	class CompareCondition final : public ICondition
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(CompareCondition, ICondition)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_leftVariable, "LeftVariable", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_rightVariable, "RightVariable", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_type, "Type", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		CompareCondition() = default;
		~CompareCondition() = default;

	public:
		bool IsResult() const override;

	private:
		IConditionVariableSharedPtr _leftVariable;
		IConditionVariableSharedPtr _rightVariable;
		CompareConditionType _type;
	};
}

#endif // _COMPARE_CONDITION_HEADER_
