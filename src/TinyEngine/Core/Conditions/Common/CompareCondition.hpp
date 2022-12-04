#ifndef _COMPARE_CONDITION_HEADER_
#define _COMPARE_CONDITION_HEADER_

#include <TinyEngine/Core/Conditions/Condition.hpp>
#include <TinyEngine/Core/Constants.hpp>
#include <TinyEngine/Core/Conditions/ConditionVariable.hpp>

namespace TinyEngine
{
	class CompareCondition final : public Condition
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(CompareCondition, Condition)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_leftVariable, "LeftVariable", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_rightVariable, "RightVariable", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_operation, "Operation", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		CompareCondition() = default;
		~CompareCondition() = default;

	public:
		void OnInit() override;
		bool IsResult() const override;

	private:
		BaseConditionVariableSharedPtr _leftVariable;
		BaseConditionVariableSharedPtr _rightVariable;
		CompareConditionOperation _operation;
	};
}

#endif // _COMPARE_CONDITION_HEADER_
