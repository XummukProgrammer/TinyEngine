#include "Entity.hpp"

#include <TinyEngine/World/Component.hpp>

namespace TinyEngine
{
	void Entity::OnInit()
	{
		for (const auto& component : _components)
		{
			component->OnInit();
		}
	}

	void Entity::OnDeinit()
	{
		for (const auto& component : _components)
		{
			component->OnDeinit();
		}
	}

	void Entity::OnUpdate()
	{
		for (const auto& component : _components)
		{
			component->OnUpdate();
		}
	}
}
