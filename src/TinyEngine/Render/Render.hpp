#ifndef _RENDER_HEADER_
#define _RENDER_HEADER_

#include <TinyEngine/Utils/Singleton.hpp>

#include <memory>

namespace TinyEngine::Core
{
	class Context;
}

namespace TinyEngine::Render
{
	class Layers;

	class Render final : public Utils::Singleton<Render>
	{
	public:
		using ContextPtr = std::shared_ptr<Core::Context>;
		using LayersPtr = std::shared_ptr<Layers>;

	public:
		Render();
		~Render() = default;

	public:
		virtual void OnPreInit(const ContextPtr& context);
		virtual void OnInit(const ContextPtr& context);
		virtual void OnDeinit(const ContextPtr& context);

		virtual void OnUpdate(const ContextPtr& context);
		virtual void OnDraw(const ContextPtr& context);

	public:
		LayersPtr GetLayers() const;

	private:
		LayersPtr _layers;
	};
}

#endif // _RENDER_HEADER_
