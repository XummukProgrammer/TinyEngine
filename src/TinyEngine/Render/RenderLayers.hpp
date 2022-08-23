#ifndef _RENDER_LAYERS_HEADER_
#define _RENDER_LAYERS_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <map>

namespace TinyEngine
{
	class RenderLayers final
	{
	public:
		RenderLayers() = default;
		~RenderLayers() = default;

	public:
		void Update(float deltaTime);
		void Draw(IRenderWindowSharedPtr renderWindowPtr);

	public:
		void CreateLayer(int layerId);
		RenderLayerSharedPtr GetLayer(int layerId) const;
		RenderLayerSharedPtr GetOrCreateLayer(int layerId);
		void RemoveLayer(int layerId);
		bool HasLayer(int layerId) const;

	private:
		std::map<int, RenderLayerSharedPtr> _layers;
	};
};

#endif // _RENDER_LAYERS_HEADER_
