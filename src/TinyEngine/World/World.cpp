#include "World.hpp"

#include <TinyEngine/World/Entity.hpp>

namespace TinyEngine
{
	void World::OnInit()
	{
		for (const auto& entity : _entities)
		{
			entity->OnInit();
		}
	}

	void World::OnDeinit()
	{
		for (const auto& entity : _entities)
		{
			entity->OnDeinit();
		}
	}

	void World::OnUpdate()
	{
		for (const auto& entity : _entities)
		{
			entity->OnUpdate();
		}
	}
}
