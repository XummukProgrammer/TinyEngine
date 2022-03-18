#ifndef _LAYERS_HEADER_
#define _LAYERS_HEADER_

#include <memory>
#include <unordered_map>
#include <string>

namespace TinyEngine::Render
{
	class ILayer;

	class Layers final
	{
	public:
		using ILayerPtr = std::shared_ptr<ILayer>;

	public:
		Layers() = default;
		virtual ~Layers() = default;

	public:
		void OnPreInit();
		void OnInit();
		void OnDeinit();

		void OnUpdate();
		void OnDraw();

	public:
		void AddLayer(std::string_view key, const ILayerPtr& layer);
		ILayerPtr GetLayer(std::string_view key) const;
		void RemoveLayer(std::string_view key);
		void RemoveLayers();

	private:
		void TryRemoveLayers();

	private:
		std::unordered_map<std::string, ILayerPtr> _layers;
		bool _isRemoveLayers = false;
	};
}

#endif // _LAYERS_HEADER_
