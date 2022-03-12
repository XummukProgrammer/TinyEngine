#include "Layers.hpp"
#include <TinyEngine/Render/ILayer.hpp>

namespace TinyEngine::Render
{
	void Layers::OnPreInit(const ContextPtr& context)
	{ 
	}

	void Layers::OnInit(const ContextPtr& context)
	{ 
	}

	void Layers::OnDeinit(const ContextPtr& context)
	{ 
	}

	void Layers::OnUpdate(const ContextPtr& context)
	{ 
		TryRemoveLayers(context);

		for (const auto& [ key, layer ] : _layers)
		{
			if (layer->IsValid())
			{
				layer->OnUpdate(context);
			}
		}
	}

	void Layers::OnDraw(const ContextPtr& context)
	{ 
		for (const auto& [ key, layer ] : _layers)
		{
			if (layer->IsValid())
			{
				layer->OnDraw(context);
			}
		}
	}

	void Layers::AddLayer(const ContextPtr& context, std::string_view key, const ILayerPtr& layer)
	{ 
		_layers[std::string{key}] = layer;
		layer->OnInit(context);
	}

	Layers::ILayerPtr Layers::GetLayer(std::string_view key) const
	{
		auto it = _layers.find(std::string{key});

		if (it != _layers.end())
		{
			return it->second;
		}

		return nullptr;
	}

	void Layers::RemoveLayer(std::string_view key)
	{ 
		if (auto layer = GetLayer(key))
		{
			layer->Remove();
		}
	}

	void Layers::RemoveLayers()
	{ 
		_isRemoveLayers = true;
	}

	void Layers::TryRemoveLayers(const ContextPtr& context)
	{ 
		auto onRemoveLayer = [context](const auto& layer)
		{
			layer->OnDeinit(context);
		};

		if (_isRemoveLayers)
		{
			for (const auto& [ key, layer ] : _layers)
			{
				onRemoveLayer(layer);
			}

			_layers.clear();
			_isRemoveLayers = false;

			return;
		}

		for (auto it = _layers.begin(); it != _layers.end();)
		{
			auto& layer = it->second;

			if (layer->IsRemoved())
			{
				onRemoveLayer(layer);

				it = _layers.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
}
