#ifndef _STATE_CONDITION_TRANSITION_HEADER_
#define _STATE_CONDITION_TRANSITION_HEADER_

#include <TinyEngine/Core/States/StateTransition.hpp>
#include <TinyEngine/Core/Conditions/Condition.hpp>

namespace TinyEngine
{
	class StateConditionTransition final : public StateTransition
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(StateConditionTransition, StateTransition)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_condition, "Condition", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		StateConditionTransition() = default;
		~StateConditionTransition() = default;

	public:
		void OnInit() override;
		bool CanChangeState() const override;

	private:
		ConditionSharedPtr _condition;
	};
}

#endif // _STATE_CONDITION_TRANSITION_HEADER_
