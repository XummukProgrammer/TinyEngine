#ifndef _CONDITION_HEADER_
#define _CONDITION_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

namespace TinyEngine
{
	class ICondition : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(ICondition)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		ICondition() = default;
		virtual ~ICondition() = default;

	public:
		virtual bool IsResult() const = 0;
	};
}

#endif // _CONDITION_HEADER_
