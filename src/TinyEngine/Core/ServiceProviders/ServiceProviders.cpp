#include "ServiceProviders.hpp"

#include <TinyEngine/Core/ServiceProviders/IServiceProvider.hpp>

namespace TinyEngine
{
	void ServiceProviders::AddProvider(ServiceProviderPriority priority, IServiceProviderPtr provider)
	{
		_providers[priority].push_back(provider);
	}

	void ServiceProviders::OnInit()
	{
		ForEach([](ServiceProviderPriority priority, IServiceProviderPtr provider)
		{
			provider->OnServiceInit();
			return false;
		});
	}

	void ServiceProviders::OnDeinit()
	{
		ForEach([](ServiceProviderPriority priority, IServiceProviderPtr provider)
		{
			provider->OnServiceDeinit();
			return false;
		});
	}

	void ServiceProviders::OnExecute()
	{
		ForEach([](ServiceProviderPriority priority, IServiceProviderPtr provider)
		{
			provider->OnServiceExecute();
			return false;
		});
	}

	void ServiceProviders::OnUpdate()
	{
		ForEach([](ServiceProviderPriority priority, IServiceProviderPtr provider)
		{
			provider->OnServiceUpdate();
			return false;
		});
	}

	void ServiceProviders::ForEach(const ForEachCallback& callback)
	{
		if (!callback)
		{
			return;
		}

		for (const auto& node : _providers)
		{
			for (const auto& provider : node.second)
			{
				if (callback(node.first, provider))
				{
					return;
				}
			}
		}
	}
}
