#ifndef _WORLD_HEADER_
#define _WORLD_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/Core/World/Entity.hpp>
#include <TinyEngine/Core/ServiceProviders/IServiceProvider.hpp>

namespace TinyEngine
{
	class WorldEntities final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(WorldEntities)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_entities, "Entities", "Entities");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		WorldEntities() = default;
		~WorldEntities() = default;

	public:
		std::vector<Entity>& GetEntities() { return _entities; }
		const std::vector<Entity>& GetConstEntities() const { return _entities; }

	private:
		std::vector<Entity> _entities;
	};

	class IWorldServiceProvider : public IServiceProvider
	{
	public:
		IWorldServiceProvider() = default;
		virtual ~IWorldServiceProvider() = default;

	public:
		virtual void LoadWorld() = 0;
	};

	namespace Services
	{
		void RegisterWorldServiceProvider();
	}
}

#endif // _WORLD_HEADER_
