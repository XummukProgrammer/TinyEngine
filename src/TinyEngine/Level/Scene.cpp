#include "Scene.hpp"

#include <TinyEngine/Core/Context.hpp>
#include <TinyEngine/Level/Entity.hpp>
#include <TinyEngine/Level/LevelManager.hpp>

namespace TinyEngine::Level
{
	void Scene::OnEnter()
	{ 
		OnLoadEntities();
		OnInitEntities();
	}

	void Scene::OnExit()
	{ 
		OnDeinitEntities();
		OnRemoveEntities();
	}

	void Scene::OnRemoveEntities()
	{ 
		RemoveEntities();
	}

	const std::vector<Scene::EntityPtr>& Scene::GetEntities() const
	{
		return _entities;
	}

	void Scene::RemoveEntities()
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

	Scene::EntityPtr Scene::CreateEntity()
	{
		auto entity = LevelManager::GetInstance().CreateEntity();
		return entity;
	}

	void Scene::AddEntity(const EntityPtr& entity)
	{ 
		LevelManager::GetInstance().AddEntity(entity);
		_entities.push_back(entity);
	}

	void Scene::RemoveEntity(const EntityPtr& entity)
	{ 
		LevelManager::GetInstance().RemoveEntity(entity);

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

	void Scene::OnInitEntities()
	{ 
		for (const auto& entity : _entities)
		{
			entity->OnInit();
		}
	}

	void Scene::OnDeinitEntities()
	{ 
		for (const auto& entity : _entities)
		{
			entity->OnDeinit();
		}
	}
}
