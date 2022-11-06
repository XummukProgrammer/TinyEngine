#ifndef _INTERFACE_SERVICE_PROVIDER_HEADER_
#define _INTERFACE_SERVICE_PROVIDER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

namespace TinyEngine
{
	class IServiceProvider
	{
	public:
		IServiceProvider() = default;
		virtual ~IServiceProvider() = default;

	public:
		virtual void OnServiceInit() {}
		virtual void OnServiceDeinit() {}
		virtual void OnServiceExecute() {}
		virtual void OnServiceUpdate() {}
	};
}

#endif // _INTERFACE_SERVICE_PROVIDER_HEADER_
