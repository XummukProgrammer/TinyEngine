#include "RenderLayers.hpp"

#include <TinyEngine/Render/RenderLayer.hpp>

#include <TinyEngine/Core/Logger.hpp>

namespace TinyEngine
{
	void RenderLayers::CreateLayer(int layerId)
	{
		TINY_ENGINE_PRINT_INFO("Create layer: " + std::to_string(layerId));
		_layers[layerId] = std::make_shared<RenderLayer>();
	}

	RenderLayerSharedPtr RenderLayers::GetLayer(int layerId) const
	{
		auto it = _layers.find(layerId);
		if (it != _layers.end())
		{
			return it->second;
		}
		return nullptr;
	}

	RenderLayerSharedPtr RenderLayers::GetOrCreateLayer(int layerId)
	{
		if (auto layer = GetLayer(layerId))
		{
			return layer;
		}
		CreateLayer(layerId);
		return GetLayer(layerId);
	}

	void RenderLayers::RemoveLayer(int layerId)
	{
		TINY_ENGINE_PRINT_INFO("Remove layer: " + std::to_string(layerId));
		auto it = _layers.find(layerId);
		if (it != _layers.end())
		{
			_layers.erase(it);
		}
	}

	bool RenderLayers::HasLayer(int layerId) const
	{
		return _layers.find(layerId) != _layers.end();
	}

	void RenderLayers::Update(float deltaTime)
	{
		for (const auto& [ layerId, layer ] : _layers)
		{
			layer->Update(deltaTime);
		}
	}

	void RenderLayers::Draw()
	{
		for (const auto& [ layerId, layer ] : _layers)
		{
			layer->Draw();
		}
	}
}
