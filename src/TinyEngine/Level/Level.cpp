﻿#include "Level.hpp"

#include <TinyEngine/Level/Entity.hpp>
#include <TinyEngine/Level/Scene.hpp>

namespace TinyEngine::Level
{
	void Level::OnPreInit()
	{ 
	}

	void Level::OnInit()
	{ 
	}

	void Level::OnDeinit()
	{ 
	}

	void Level::OnUpdate()
	{
		TryRemoveScenes();
		TryUpdateCurrentScene();

		TryRemoveEntities();

		for (const auto& entity : _entities)
		{
			if (entity->IsValid())
			{
				entity->OnUpdate();
			}
		}
	}

	void Level::OnDraw()
	{ 

	}

	void Level::OnEvent()
	{ 
	}

	Level::EntityPtr Level::CreateEntity() const
	{
		auto entity = std::make_shared<Entity>();
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

	void Level::RemoveEntities()
	{ 
		_isRemovedEntities = true;
	}

	void Level::AddScene(std::string_view key, const ScenePtr& scene)
	{ 
		_scenes[std::string{key}] = scene;
	}

	void Level::TryUpdateCurrentScene()
	{ 
		if (!_nextScene)
		{
			return;
		}

		if (_currentScene)
		{
			_currentScene->OnExit();
		}

		_currentScene = _nextScene;
		_currentScene->OnEnter();

		_nextScene.reset();
	}

	void Level::TryRemoveScenes()
	{ 
		if (_isRemovedScenes)
		{
			_scenes.clear();
			_isRemovedScenes = false;

			return;
		}

		bool isRemovedCurrentScene = false;

		for (auto it = _scenes.begin(); it != _scenes.end();)
		{
			auto& scene = it->second;

			if (scene->IsRemoved())
			{
				if (scene == _currentScene)
				{
					isRemovedCurrentScene = true;
				}

				it = _scenes.erase(it);
			}
			else
			{
				++it;
			}
		}

		if (isRemovedCurrentScene)
		{
			if (!_scenes.empty())
			{
				SetCurrentScene(_scenes.at(0));
			}
			else
			{
				_currentScene.reset();
			}
		}
	}

	void Level::TryRemoveEntities()
	{
		auto onRemoveEntity = [](const auto& entity)
		{
			entity->OnDeinit();
		};

		if (_isRemovedEntities)
		{
			for (const auto& entity : _entities)
			{
				onRemoveEntity(entity);
			}

			_entities.clear();
			_isRemovedEntities = false;

			return;
		}

		for (auto it = _entities.begin(); it != _entities.end();)
		{
			auto& entity = *it;

			if (entity->IsRemoved())
			{
				onRemoveEntity(entity);
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

	Level::ScenePtr Level::GetCurrentScene() const
	{
		return _currentScene;
	}

	Level::ScenePtr Level::GetScene(std::string_view key) const
	{
		auto it = _scenes.find(std::string{key});

		if (it != _scenes.end())
		{
			return it->second;
		}

		return nullptr;
	}

	void Level::RemoveScenes()
	{
		_isRemovedScenes = true;
	}
}