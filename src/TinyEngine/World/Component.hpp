#ifndef _COMPONENT_HEADER_
#define _COMPONENT_HEADER_

#include <TinyEngine/Data/Meta/MetaDefines.hpp>

namespace TinyEngine
{
	class Component : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Component)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Component() = default;
		virtual ~Component() = default;

	public:
		virtual void OnInit() {}
		virtual void OnDeinit() {}
		virtual void OnUpdate() {}
	};
}

#endif // _COMPONENT_HEADER_
