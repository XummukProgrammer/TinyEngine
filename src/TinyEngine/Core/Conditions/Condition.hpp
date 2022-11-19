#ifndef _CONDITION_HEADER_
#define _CONDITION_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

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
		virtual bool IsResult() const = 0;
	};
}

#endif // _CONDITION_HEADER_
