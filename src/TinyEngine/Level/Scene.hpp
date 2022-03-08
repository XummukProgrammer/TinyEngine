#ifndef _SCENE_HEADER_
#define _SCENE_HEADER_

#include <memory>
#include <vector>

namespace TinyEngine::Core
{
	class Context;
}

namespace TinyEngine::Level
{
	class Entity;

	class Scene : public std::enable_shared_from_this<Scene>
	{
	public:
		using ContextPtr = std::shared_ptr<Core::Context>;
		using EntityPtr = std::shared_ptr<Entity>;

	public:
		Scene() = default;
		virtual ~Scene() = default;

	public:
		virtual void OnEnter(const ContextPtr& context);
		virtual void OnExit(const ContextPtr& context);

		virtual void OnUpdate(const ContextPtr& context) {}

	protected:
		virtual void OnLoadEntities(const ContextPtr& context) {}
		virtual void OnRemoveEntities(const ContextPtr& context);

		const std::vector<EntityPtr>& GetEntities() const;
		void AddEntity(const ContextPtr& context, const EntityPtr& entity);

		// TODO: Доработать
		void RemoveAllEntities();

	private:
		void OnInitEntities(const ContextPtr& context);
		void OnDeinitEntities(const ContextPtr& context);

	private:
		std::vector<EntityPtr> _entities;
	};
}

#endif // _SCENE_HEADER_
