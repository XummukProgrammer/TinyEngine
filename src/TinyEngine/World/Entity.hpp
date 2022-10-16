#ifndef _ENTITY_HEADER_
#define _ENTITY_HEADER_

#include <TinyEngine/Data/Meta/MetaDefines.hpp>

namespace TinyEngine
{
	class Entity : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Entity)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Entity() = default;
		virtual ~Entity() = default;

	public:
		void OnInit();
		void OnDeinit();
		void OnUpdate();

	private:
		std::vector<ComponentSharedPtr> _components;
	};
}

#endif // _ENTITY_HEADER_
