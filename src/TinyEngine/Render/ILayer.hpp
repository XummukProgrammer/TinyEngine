#ifndef _INTERFACE_LAYER_HEADER_
#define _INTERFACE_LAYER_HEADER_

#include <memory>
#include <string>

namespace TinyEngine::Core
{
	class Context;
}

namespace TinyEngine::Render
{
	class ILayer
	{
	public:
		using ContextPtr = std::shared_ptr<Core::Context>;

	public:
		ILayer() = default;
		virtual ~ILayer() = default;

	public:
		virtual void OnInit(const ContextPtr& context) {}
		virtual void OnDeinit(const ContextPtr& context) {}

		virtual void OnUpdate(const ContextPtr& context) {}
		virtual void OnDraw(const ContextPtr& context) {}

	public:
		bool IsValid() const;

		void Remove();
		bool IsRemoved() const;

	private:
		bool _isRemoved = false;
	};
}

#endif // _INTERFACE_LAYER_HEADER_
