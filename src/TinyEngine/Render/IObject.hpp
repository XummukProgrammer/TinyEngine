#ifndef _INTERFACE_OBJECT_HEADER_
#define _INTERFACE_OBJECT_HEADER_

#include <memory>

namespace TinyEngine::Core
{
	class Context;
}

namespace TinyEngine::Render
{
	class IObject
	{
	public:
		using ContextPtr = std::shared_ptr<Core::Context>;

	public:
		IObject() = default;
		virtual ~IObject() = default;

	public:
		virtual void OnInit(const ContextPtr& context) {}
		virtual void OnDeinit(const ContextPtr& context) {}

		virtual void OnUpdate(const ContextPtr& context) {}
		virtual void OnDraw(const ContextPtr& context) {}
	};
}

#endif // _INTERFACE_OBJECT_HEADER_
