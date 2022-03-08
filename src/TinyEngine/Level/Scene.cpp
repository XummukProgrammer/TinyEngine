#include "Scene.hpp"

#include <TinyEngine/Core/Context.hpp>
#include <TinyEngine/Level/Entity.hpp>

namespace TinyEngine::Level
{
	void Scene::OnEnter(const ContextPtr& context)
	{ 
		OnLoadEntities(context);
		OnInitEntities(context);
	}

	void Scene::OnExit(const ContextPtr& context)
	{ 
		OnDeinitEntities(context);
		OnRemoveEntities(context);
	}

	void Scene::OnRemoveEntities(const ContextPtr& context)
	{ 
		RemoveAllEntities();
	}

	const std::vector<Scene::EntityPtr>& Scene::GetEntities() const
	{
		return _entities;
	}

	void Scene::AddEntity(const ContextPtr& context, const EntityPtr& entity)
	{ 
		context->AddEntity(entity);
		_entities.push_back(entity);
	}

	void Scene::RemoveAllEntities()
	{
		_entities.clear();
	}

	void Scene::OnInitEntities(const ContextPtr& context)
	{ 
		for (const auto& entity : _entities)
		{
			entity->OnInit();
		}
	}

	void Scene::OnDeinitEntities(const ContextPtr& context)
	{ 
		for (const auto& entity : _entities)
		{
			entity->OnDeinit();
		}
	}
}
