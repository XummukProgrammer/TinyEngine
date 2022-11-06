#ifndef _SERVICE_PROVIDERS_HEADER_
#define _SERVICE_PROVIDERS_HEADER_

#include <TinyEngine/Core/Data/Singleton.hpp>
#include <TinyEngine/Core/Forwards.hpp>

#include <map>
#include <vector>
#include <functional>

namespace TinyEngine
{
	class ServiceProviders final : public Singleton<ServiceProviders>
	{
	public:
		using ForEachCallback = std::function<bool(ServiceProviderPriority, IServiceProviderPtr)>;

	public:
		ServiceProviders() = default;
		~ServiceProviders() = default;

	public:
		void AddProvider(ServiceProviderPriority priority, IServiceProviderPtr provider);
		template<typename T>
		T* GetProvider();

		void OnInit();
		void OnDeinit();
		void OnExecute();
		void OnUpdate();

	private:
		void ForEach(const ForEachCallback& callback);

	private:
		std::map<ServiceProviderPriority, std::vector<IServiceProviderPtr>> _providers;
	};

	template<typename T>
	inline T* ServiceProviders::GetProvider()
	{
		T* resultProvider = nullptr;
		ForEach([&resultProvider](ServiceProviderPriority priority, IServiceProviderPtr provider)
		{
			if (auto castedProvider = (T*)provider)
			{
				resultProvider = castedProvider;
				return true;
			}
			return false;
		});
		return resultProvider;
	}
}

#endif // _SERVICE_PROVIDERS_HEADER_
