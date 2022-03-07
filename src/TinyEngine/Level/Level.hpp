#ifndef _LEVEL_HEADER_
#define _LEVEL_HEADER_

#include <memory>

namespace TinyEngine::Core
{
	class Context;
}

namespace TinyEngine::Level
{
	class Level final
	{
	public:
		using ContextPtr = std::shared_ptr<Core::Context>;

	public:
		Level() = default;
		~Level() = default;

	public:
		void OnPreInit(const ContextPtr& context);
		void OnInit(const ContextPtr& context);
		void OnDeinit(const ContextPtr& context);

		void OnUpdate(const ContextPtr& context);
		void OnDraw(const ContextPtr& context);
		void OnEvent(const ContextPtr& context);

	private:

	};
}

#endif // _LEVEL_HEADER_
