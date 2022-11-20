#ifndef _CONDITION_HEADER_
#define _CONDITION_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

#include <TinyEngine/Core/Conditions/ConditionContext.hpp>

namespace TinyEngine
{
	class Condition : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Condition)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Condition() = default;
		virtual ~Condition() = default;

	public:
		virtual void OnInit() {}
		virtual bool IsResult() const = 0;

	public:
		ConditionContext& GetLocalContext() { return _localContext; }
		const ConditionContext& GetConstLocalContext() const { return _localContext; }

	private:
		ConditionContext _localContext;
	};
}

#endif // _CONDITION_HEADER_
