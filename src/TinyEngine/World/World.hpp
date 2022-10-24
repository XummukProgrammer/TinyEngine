#ifndef _WORLD_HEADER_
#define _WORLD_HEADER_

#include <TinyEngine/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/World/Entity.hpp>

namespace TinyEngine
{
	class World final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(World)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_entities, "Entities", "Entities");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		World() = default;
		~World() = default;

	public:
		void OnInit();
		void OnDeinit();
		void OnUpdate();

	private:
		std::vector<Entity> _entities;
	};
}

#endif // _WORLD_HEADER_
