﻿#include "LevelManager.hpp"

#include <TinyEngine/Level/Entity.hpp>
#include <TinyEngine/Level/Scene.hpp>

namespace TinyEngine::Level
{
	void LevelManager::OnPreInit()
	{ 
	}

	void LevelManager::OnInit()
	{ 
	}

	void LevelManager::OnDeinit()
	{ 
	}

	void LevelManager::OnUpdate()
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

	void LevelManager::OnDraw()
	{ 

	}

	void LevelManager::OnEvent()
	{ 
	}

	LevelManager::EntityPtr LevelManager::CreateEntity() const
	{
		auto entity = std::make_shared<Entity>();
		return entity;
	}

	void LevelManager::AddEntity(const EntityPtr& entity)
	{ 
		_entities.push_back(entity);
	}

	void LevelManager::RemoveEntity(const EntityPtr& entity)
	{ 
		entity->Remove();
	}

	void LevelManager::RemoveEntities()
	{ 
		_isRemovedEntities = true;
	}

	void LevelManager::AddScene(std::string_view key, const ScenePtr& scene)
	{ 
		_scenes[std::string{key}] = scene;
	}

	void LevelManager::TryUpdateCurrentScene()
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

	void LevelManager::TryRemoveScenes()
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

	void LevelManager::TryRemoveEntities()
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

	void LevelManager::SetCurrentScene(const ScenePtr& scene)
	{ 
		_nextScene = scene;
	}

	LevelManager::ScenePtr LevelManager::GetCurrentScene() const
	{
		return _currentScene;
	}

	LevelManager::ScenePtr LevelManager::GetScene(std::string_view key) const
	{
		auto it = _scenes.find(std::string{key});

		if (it != _scenes.end())
		{
			return it->second;
		}

		return nullptr;
	}

	void LevelManager::RemoveScenes()
	{
		_isRemovedScenes = true;
	}
}