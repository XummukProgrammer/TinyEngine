#ifndef _SCENE_HEADER_
#define _SCENE_HEADER_

#include <memory>

namespace TinyEngine::Core
{
	class Context;
}

namespace TinyEngine::Level
{
	class Scene : public std::enable_shared_from_this<Scene>
	{
	public:
		using ContextPtr = std::shared_ptr<Core::Context>;

	public:
		Scene() = default;
		virtual ~Scene() = default;

	public:
		virtual void OnCreate(const ContextPtr& context) {}

		virtual void OnEnter(const ContextPtr& context) {}
		virtual void OnExit(const ContextPtr& context) {}

		virtual void OnUpdate(const ContextPtr& context) {}
	};
}

#endif // _SCENE_HEADER_
