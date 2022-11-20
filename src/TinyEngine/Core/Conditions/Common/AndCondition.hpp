#ifndef _AND_CONDITION_HEADER_
#define _AND_CONDITION_HEADER_

#include <TinyEngine/Core/Conditions/Condition.hpp>

namespace TinyEngine
{
	class AndCondition final : public Condition
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(AndCondition, Condition)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_conditions, "Conditions", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		AndCondition() = default;
		~AndCondition() = default;

	public:
		void OnInit() override;
		bool IsResult() const override;

	private:
		std::vector<ConditionSharedPtr> _conditions;
	};
}

#endif // _AND_CONDITION_HEADER_
