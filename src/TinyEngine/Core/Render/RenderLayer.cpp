﻿#include "RenderLayer.hpp"

#include <TinyEngine/Core/Render/RenderObject.hpp>
#include <TinyEngine/Core/Render/RenderWindow.hpp>

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

	void RenderLayer::Draw()
	{
		for (const auto& object : _objects)
		{
			object->Draw();
		}
	}

	void RenderLayer::AddRenderObject(RenderObjectSharedPtr object)
	{
		object->SetLayerId(GetLayerId());
		_objects.push_back(object);
	}

	void RenderLayer::RemoveRenderObject(RenderObjectSharedPtr object)
	{
		const auto it = GetConstObjectIterator(object);
		if (it != _objects.end())
		{
			_objects.erase(it);
		}
	}

	bool RenderLayer::HasRenderObject(RenderObjectSharedPtr object) const
	{
		return GetConstObjectIterator(object) != _objects.end();
	}

	RenderLayer::ObjectsList::const_iterator RenderLayer::GetConstObjectIterator(RenderObjectSharedPtr object) const
	{
		return std::find(_objects.begin(), _objects.end(), object);
	}
}
