#include "Render.hpp"

#include <TinyEngine/Render/Layers.hpp>

namespace TinyEngine::Render
{
	Render::Render()
		: _layers(std::make_shared<Layers>())
	{ 
	}

	void Render::OnPreInit(const ContextPtr& context)
	{ 
		_layers->OnPreInit(context);
	}

	void Render::OnInit(const ContextPtr& context)
	{ 
		_layers->OnInit(context);
	}

	void Render::OnDeinit(const ContextPtr& context)
	{ 
		_layers->OnDeinit(context);
	}

	void Render::OnUpdate(const ContextPtr& context)
	{ 
		_layers->OnUpdate(context);
	}

	void Render::OnDraw(const ContextPtr& context)
	{ 
		_layers->OnDraw(context);
	}

	Render::LayersPtr Render::GetLayers() const
	{
		return _layers;
	}
}
