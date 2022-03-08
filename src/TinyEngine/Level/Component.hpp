#ifndef _COMPONENT_HEADER_
#define _COMPONENT_HEADER_

#include <memory>

namespace TinyEngine::Core
{
	class Context;
}

namespace TinyEngine::Level
{
	class Component
	{
	public:
		using ContextPtr = std::shared_ptr<Core::Context>;

	public:
		Component() = default;
		virtual ~Component() = default;

	public:
		virtual void OnInit(const ContextPtr& context) {}
		virtual void OnDeinit(const ContextPtr& context) {}

		virtual void OnUpdate(const ContextPtr& context) {}
	};
}

#endif // _COMPONENT_HEADER_
