#include "RenderLayer.hpp"

#include <TinyEngine/Render/IRenderObject.hpp>
#include <TinyEngine/Render/IRenderWindow.hpp>

#include <TinyEngine/Core/Logger.hpp>

namespace TinyEngine
{
	void RenderLayer::Update(float deltaTime)
	{
		for (const auto& object : _objects)
		{
			object->Update(deltaTime);
		}
	}

	void RenderLayer::Draw(IRenderWindowSharedPtr renderWindowPtr)
	{
		for (const auto& object : _objects)
		{
			renderWindowPtr->Draw(object.get());
		}
	}

	void RenderLayer::AddRenderObject(IRenderObjectSharedPtr object)
	{
		TINY_ENGINE_PRINT_INFO("Added new render object");
		_objects.push_back(object);
	}

	void RenderLayer::RemoveRenderObject(IRenderObjectSharedPtr object)
	{
		TINY_ENGINE_PRINT_INFO("Remove render object");
		const auto it = GetConstObjectIterator(object);
		if (it != _objects.end())
		{
			_objects.erase(it);
		}
	}

	bool RenderLayer::HasRenderObject(IRenderObjectSharedPtr object) const
	{
		return GetConstObjectIterator(object) != _objects.end();
	}

	RenderLayer::ObjectsList::const_iterator RenderLayer::GetConstObjectIterator(IRenderObjectSharedPtr object) const
	{
		return std::find(_objects.begin(), _objects.end(), object);
	}
}
