#include "Render.hpp"

#include <TinyEngine/Render/Layers.hpp>

namespace TinyEngine::Render
{
	Render::Render()
		: _layers(std::make_shared<Layers>())
	{ 
	}

	void Render::OnPreInit()
	{ 
		_layers->OnPreInit();
	}

	void Render::OnInit()
	{ 
		_layers->OnInit();
	}

	void Render::OnDeinit()
	{ 
		_layers->OnDeinit();
	}

	void Render::OnUpdate()
	{ 
		_layers->OnUpdate();
	}

	void Render::OnDraw()
	{ 
		_layers->OnDraw();
	}

	Render::LayersPtr Render::GetLayers() const
	{
		return _layers;
	}
}
