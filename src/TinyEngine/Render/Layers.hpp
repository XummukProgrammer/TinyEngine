#ifndef _LAYERS_HEADER_
#define _LAYERS_HEADER_

#include <memory>
#include <unordered_map>
#include <string>

namespace TinyEngine::Core
{
	class Context;
}

namespace TinyEngine::Render
{
	class ILayer;

	class Layers
	{
	public:
		using ContextPtr = std::shared_ptr<Core::Context>;
		using ILayerPtr = std::shared_ptr<ILayer>;

	public:
		Layers() = default;
		virtual ~Layers() = default;

	public:
		virtual void OnPreInit(const ContextPtr& context);
		virtual void OnInit(const ContextPtr& context);
		virtual void OnDeinit(const ContextPtr& context);

		virtual void OnUpdate(const ContextPtr& context);
		virtual void OnDraw(const ContextPtr& context);

	public:
		void AddLayer(const ContextPtr& context, std::string_view key, const ILayerPtr& layer);
		ILayerPtr GetLayer(std::string_view key) const;
		void RemoveLayer(std::string_view key);
		void RemoveLayers();

	private:
		void TryRemoveLayers(const ContextPtr& context);

	private:
		std::unordered_map<std::string, ILayerPtr> _layers;
		bool _isRemoveLayers = false;
	};
}

#endif // _LAYERS_HEADER_
