#ifndef _OR_CONDITION_HEADER_
#define _OR_CONDITION_HEADER_

#include <TinyEngine/Core/Conditions/Condition.hpp>

namespace TinyEngine
{
	class OrCondition final : public ICondition
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(OrCondition, ICondition)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_conditions, "Conditions", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		OrCondition() = default;
		~OrCondition() = default;

	public:
		bool IsResult() const override;

	private:
		std::vector<IConditionSharedPtr> _conditions;
	};
}

#endif // _OR_CONDITION_HEADER_
