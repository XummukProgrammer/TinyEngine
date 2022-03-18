#ifndef _SCENE_HEADER_
#define _SCENE_HEADER_

#include <memory>
#include <vector>

namespace TinyEngine::Level
{
	class Entity;

	class Scene
	{
	public:
		using EntityPtr = std::shared_ptr<Entity>;

	public:
		Scene() = default;
		virtual ~Scene() = default;

	public:
		virtual void OnEnter();
		virtual void OnExit();

		virtual void OnUpdate() {}

	public:
		bool IsValid() const;

		void Remove();
		bool IsRemoved() const;

		EntityPtr CreateEntity();
		void AddEntity(const EntityPtr& entity);
		void RemoveEntity(const EntityPtr& entity);
		void RemoveEntities();

	protected:
		virtual void OnLoadEntities();
		virtual void OnRemoveEntities();

		const std::vector<EntityPtr>& GetEntities() const;

	private:
		void OnInitEntities();
		void OnDeinitEntities();

	private:
		std::vector<EntityPtr> _entities;
		bool _isRemoved = false;
		bool _isEntitiesLoaded = false;
	};
}

#endif // _SCENE_HEADER_
