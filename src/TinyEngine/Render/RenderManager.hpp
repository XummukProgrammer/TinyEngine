﻿#ifndef _RENDER_HEADER_
#define _RENDER_HEADER_

#include <TinyEngine/Utils/Singleton.hpp>

#include <memory>

namespace TinyEngine::Render
{
	class Layers;

	class RenderManager final : public Utils::Singleton<RenderManager>
	{
	public:
		using LayersPtr = std::shared_ptr<Layers>;

	public:
		RenderManager();
		~RenderManager() = default;

	public:
		void OnPreInit();
		void OnInit();
		void OnDeinit();

		void OnUpdate();
		void OnDraw();

	public:
		LayersPtr GetLayers() const;

	private:
		LayersPtr _layers;
	};
}

#endif // _RENDER_HEADER_
