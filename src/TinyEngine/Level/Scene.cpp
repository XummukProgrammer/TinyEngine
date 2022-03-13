#include "Scene.hpp"

#include <TinyEngine/Core/Context.hpp>
#include <TinyEngine/Level/Entity.hpp>
#include <TinyEngine/Level/Level.hpp>

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
		RemoveEntities(context);
	}

	const std::vector<Scene::EntityPtr>& Scene::GetEntities() const
	{
		return _entities;
	}

	void Scene::RemoveEntities(const ContextPtr& context)
	{
		for (const auto& entity : _entities)
		{
			entity->Remove();
		}

		_entities.clear();
	}

	bool Scene::IsValid() const
	{
		return !IsRemoved();
	}

	void Scene::Remove()
	{ 
		_isRemoved = true;
	}

	bool Scene::IsRemoved() const
	{
		return _isRemoved;
	}

	Scene::EntityPtr Scene::CreateAndAddEntity(const ContextPtr& context)
	{
		auto entity = Level::GetInstance().CreateEntity(nullptr);

		Level::GetInstance().AddEntity(entity);
		_entities.push_back(entity);

		return entity;
	}

	void Scene::RemoveEntity(const ContextPtr& context, const EntityPtr& entity)
	{ 
		Level::GetInstance().RemoveEntity(entity);

		for (auto it = _entities.begin(); it != _entities.end(); ++it)
		{
			auto& sceneEntity = *it;

			if (sceneEntity == entity)
			{
				_entities.erase(it);
				return;
			}
		}
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
