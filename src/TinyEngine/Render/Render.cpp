#include "Render.hpp"

#include <TinyEngine/Core/Logger/Logger.hpp>
#include <TinyEngine/Core/Debug/Debug.hpp>
#include <TinyEngine/Render/SfmlRender.hpp>

namespace TinyEngine
{
	Render render;

	Render& Render::CreateSfmlWindow(const RenderWindowSettings& windowSettings)
	{
		TINY_ENGINE_INFO("Use Sfml Window");
		CreateWindow(std::make_shared<SfmlRenderWindow>(), windowSettings);
		return *this;
	}

	void RenderLayer::Update(float deltaTime)
	{
		for (const auto& object : _objects)
		{
			object->Update(deltaTime);
		}
	}

	void RenderLayer::Draw(IRenderWindowPtr renderWindowPtr)
	{
		for (const auto& object : _objects)
		{
			renderWindowPtr->Draw(object.get());
		}
	}

	IRenderObjectPtr RenderLayer::AddRenderObject(const IRenderObjectBuilder& builder)
	{
		TINY_ENGINE_INFO("Added new render object");
		auto object = builder.GetPtr();
		_objects.push_back(object);
		return object;
	}

	void RenderLayer::RemoveRenderObject(IRenderObjectPtr object)
	{
		TINY_ENGINE_INFO("Remove render object");
		const auto it = GetConstObjectIterator(object);
		if (it != _objects.end())
		{
			_objects.erase(it);
		}
	}

	bool RenderLayer::HasRenderObject(IRenderObjectPtr object) const
	{
		return GetConstObjectIterator(object) != _objects.end();
	}

	RenderLayer::ObjectsList::const_iterator RenderLayer::GetConstObjectIterator(IRenderObjectPtr object) const
	{
		return std::find(_objects.begin(), _objects.end(), object);
	}

	void RenderLayers::CreateLayer(int layerId)
	{
		TINY_ENGINE_INFO("Create layer: " + std::to_string(layerId));
		_layers[layerId] = std::make_shared<RenderLayer>();
	}

	RenderLayerPtr RenderLayers::GetLayer(int layerId) const
	{
		auto it = _layers.find(layerId);
		if (it != _layers.end())
		{
			return it->second;
		}
		return nullptr;
	}

	RenderLayerPtr RenderLayers::GetOrCreateLayer(int layerId)
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
		TINY_ENGINE_INFO("Remove layer: " + std::to_string(layerId));
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

	void RenderLayers::Draw(IRenderWindowPtr renderWindowPtr)
	{
		for (const auto& [ layerId, layer ] : _layers)
		{
			layer->Draw(renderWindowPtr);
		}
	}

	Render& Render::Execute()
	{
		TINY_ENGINE_ASSERT(_renderWindowPtr.get(), "Render Window not inited");

		while (!_renderWindowPtr->IsClosed())
		{
			_renderWindowPtr->ExtractEvents();
			UpdateObjects(0.f);
			_renderWindowPtr->Clear();
			DrawObjects();
			_renderWindowPtr->Display();
		}

		return *this;
	}

	Render& Render::Destroy()
	{
		TINY_ENGINE_INFO("Destroy");

		_renderWindowPtr.reset();

		return *this;
	}

	void Render::UpdateObjects(float deltaTime)
	{
		_renderLayers.Update(deltaTime);
	}

	void Render::DrawObjects()
	{
		_renderLayers.Draw(_renderWindowPtr);
	}

	void Render::CreateWindow(IRenderWindowPtr window, const RenderWindowSettings& windowSettings)
	{
		_renderWindowPtr = window;
		_renderWindowPtr->Create(windowSettings);
	}
}
