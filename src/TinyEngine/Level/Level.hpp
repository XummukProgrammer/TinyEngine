#ifndef _LEVEL_HEADER_
#define _LEVEL_HEADER_

#include <memory>
#include <vector>

namespace TinyEngine::Core
{
	class Context;
}

namespace TinyEngine::Level
{
	class Entity;
	class Scene;

	class Level final
	{
	public:
		using ContextPtr = std::shared_ptr<Core::Context>;
		using EntityPtr = std::shared_ptr<Entity>;
		using ScenePtr = std::shared_ptr<Scene>;

	public:
		Level() = default;
		~Level() = default;

	public:
		void OnPreInit(const ContextPtr& context);
		void OnInit(const ContextPtr& context);
		void OnDeinit(const ContextPtr& context);

		void OnUpdate(const ContextPtr& context);
		void OnDraw(const ContextPtr& context);
		void OnEvent(const ContextPtr& context);

		EntityPtr CreateEntity(const ContextPtr& context) const;
		void AddEntity(const EntityPtr& entity);

		void AddScene(const ContextPtr& context, const ScenePtr& scene);
		void SetCurrentScene(const ContextPtr& context, const ScenePtr& scene);

	private:
		std::vector<EntityPtr> _entities;

		std::vector<ScenePtr> _scenes;
		ScenePtr _currentScene;
	};
}

#endif // _LEVEL_HEADER_
