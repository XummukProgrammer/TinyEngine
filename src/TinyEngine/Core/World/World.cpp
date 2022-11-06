#include "World.hpp"

#include <TinyEngine/Core/World/Entity.hpp>
#include <TinyEngine/Core/Application.hpp>
#include <TinyEngine/Core/ServiceProviders/ServiceProviders.hpp>

namespace TinyEngine
{
	class WorldServiceProvider final : public IWorldServiceProvider
	{
	public:
		WorldServiceProvider() = default;
		~WorldServiceProvider() = default;

	public:
		void OnServiceInit() override;
		void OnServiceDeinit() override;
		void OnServiceUpdate() override;

	public:
		void LoadWorld() override;

	private:
		WorldEntities _worldEntities;
	};

	void WorldServiceProvider::OnServiceInit()
	{
		for (auto& entity : _worldEntities.GetEntities())
		{
			entity.OnInit();
		}
	}

	void WorldServiceProvider::OnServiceDeinit()
	{
		for (auto& entity : _worldEntities.GetEntities())
		{
			entity.OnDeinit();
		}
	}

	void WorldServiceProvider::OnServiceUpdate()
	{
		for (auto& entity : _worldEntities.GetEntities())
		{
			entity.OnUpdate();
		}
	}

	void WorldServiceProvider::LoadWorld()
	{
		const auto& worldFile = Application::GetInstance()->GetConstProject().GetWorldFile();
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, worldFile, &_worldEntities);
		OnServiceInit();
	}

	namespace Services
	{
		void RegisterWorldServiceProvider()
		{
			ServiceProviders::GetInstance()->AddProvider(ServiceProviderPriority::VeryHigh, new WorldServiceProvider());
		}
	}
}
