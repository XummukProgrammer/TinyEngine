#include "RenderManager.hpp"

#include <TinyEngine/Render/Layers.hpp>

namespace TinyEngine::Render
{
	RenderManager::RenderManager()
		: _layers(std::make_shared<Layers>())
	{ 
	}

	void RenderManager::OnPreInit()
	{ 
		_layers->OnPreInit();
	}

	void RenderManager::OnInit()
	{ 
		_layers->OnInit();
	}

	void RenderManager::OnDeinit()
	{ 
		_layers->OnDeinit();
	}

	void RenderManager::OnUpdate()
	{ 
		_layers->OnUpdate();
	}

	void RenderManager::OnDraw()
	{ 
		_layers->OnDraw();
	}

	RenderManager::LayersPtr RenderManager::GetLayers() const
	{
		return _layers;
	}
}
