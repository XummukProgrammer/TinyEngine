#ifndef _WORLD_HEADER_
#define _WORLD_HEADER_

#include <TinyEngine/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/World/Entity.hpp>

namespace TinyEngine
{
	class World : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(World)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		World() = default;
		virtual ~World() = default;

	public:
		void OnInit();
		void OnDeinit();
		void OnUpdate();

	private:
		std::vector<EntitySharedPtr> _entities;
	};
}

#endif // _WORLD_HEADER_
