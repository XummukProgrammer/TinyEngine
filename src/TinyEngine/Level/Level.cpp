#include "Level.hpp"

#include <TinyEngine/Level/Entity.hpp>
#include <TinyEngine/Level/Scene.hpp>

namespace TinyEngine::Level
{
	void Level::OnPreInit(const ContextPtr& context)
	{ 
	}

	void Level::OnInit(const ContextPtr& context)
	{ 
	}

	void Level::OnDeinit(const ContextPtr& context)
	{ 
	}

	void Level::OnUpdate(const ContextPtr& context)
	{
		TryUpdateCurrentScene(context);
		TryRemoveEntities(context);

		for (const auto& entity : _entities)
		{
			if (entity->IsValid())
			{
				entity->OnUpdate();
			}
		}
	}

	void Level::OnDraw(const ContextPtr& context)
	{ 

	}

	void Level::OnEvent(const ContextPtr& context)
	{ 
	}

	Level::EntityPtr Level::CreateEntity(const ContextPtr& context) const
	{
		auto entity = std::make_shared<Entity>();
		entity->SetContext(context);
		return entity;
	}

	void Level::AddEntity(const EntityPtr& entity)
	{ 
		_entities.push_back(entity);
	}

	void Level::RemoveEntity(const EntityPtr& entity)
	{ 
		entity->Remove();
	}

	void Level::AddScene(const ContextPtr& context, const ScenePtr& scene)
	{ 
		_scenes.push_back(scene);
	}

	void Level::TryUpdateCurrentScene(const ContextPtr& context)
	{ 
		if (!_nextScene)
		{
			return;
		}

		_currentScene = _nextScene;
		_nextScene.reset();

		for (auto it = _scenes.begin(); it != _scenes.end(); ++it)
		{
			auto& scene = *it;

			if (scene->shared_from_this() == scene)
			{
				if (_currentScene)
				{
					_currentScene->OnExit(context);
				}

				_currentScene = scene;
				_currentScene->OnEnter(context);
				return;
			}
		}
	}

	void Level::TryRemoveEntities(const ContextPtr& context)
	{
		for (auto it = _entities.begin(); it != _entities.end();)
		{
			auto& entity = *it;

			if (entity->IsRemoved())
			{
				entity->OnDeinit();
				it = _entities.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	void Level::SetCurrentScene(const ScenePtr& scene)
	{ 
		_nextScene = scene;
	}
}
