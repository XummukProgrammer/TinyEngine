#ifndef _LEVEL_HEADER_
#define _LEVEL_HEADER_

#include <TinyEngine/Utils/Singleton.hpp>

#include <memory>
#include <vector>
#include <map>
#include <string>

namespace TinyEngine::Level
{
	class Entity;
	class Scene;

	class Level final : public Utils::Singleton<Level>
	{
	public:
		using EntityPtr = std::shared_ptr<Entity>;
		using ScenePtr = std::shared_ptr<Scene>;

	public:
		Level() = default;
		~Level() = default;

	public:
		void OnPreInit();
		void OnInit();
		void OnDeinit();

		void OnUpdate();
		void OnDraw();
		void OnEvent();

	public:
		EntityPtr CreateEntity() const;
		void AddEntity(const EntityPtr& entity);
		void RemoveEntity(const EntityPtr& entity);
		void RemoveEntities();

		void AddScene(std::string_view key, const ScenePtr& scene);
		void SetCurrentScene(const ScenePtr& scene);
		ScenePtr GetCurrentScene() const;
		ScenePtr GetScene(std::string_view key) const;
		void RemoveScenes();

	private:
		void TryRemoveEntities();

		void TryUpdateCurrentScene();
		void TryRemoveScenes();

	private:
		std::vector<EntityPtr> _entities;
		bool _isRemovedEntities = false;

		std::map<std::string, ScenePtr> _scenes;
		ScenePtr _currentScene;
		ScenePtr _nextScene;
		bool _isRemovedScenes = false;
	};
}

#endif // _LEVEL_HEADER_
