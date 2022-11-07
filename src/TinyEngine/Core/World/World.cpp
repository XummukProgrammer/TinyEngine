#include "World.hpp"

#include <TinyEngine/Core/World/Entity.hpp>

namespace TinyEngine
{
	void World::OnInit()
	{
		for (auto& entity : _entities)
		{
			entity.OnInit();
		}
	}

	void World::OnDeinit()
	{
		for (auto& entity : _entities)
		{
			entity.OnDeinit();
		}
	}

	void World::OnUpdate()
	{
		for (auto& entity : _entities)
		{
			entity.OnUpdate();
		}
	}
}
