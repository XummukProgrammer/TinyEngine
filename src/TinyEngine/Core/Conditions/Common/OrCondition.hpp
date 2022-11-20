#ifndef _OR_CONDITION_HEADER_
#define _OR_CONDITION_HEADER_

#include <TinyEngine/Core/Conditions/Condition.hpp>

namespace TinyEngine
{
	class OrCondition final : public Condition
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(OrCondition, Condition)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_conditions, "Conditions", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		OrCondition() = default;
		~OrCondition() = default;

	public:
		void OnInit() override;
		bool IsResult() const override;

	private:
		std::vector<ConditionSharedPtr> _conditions;
	};
}

#endif // _OR_CONDITION_HEADER_
