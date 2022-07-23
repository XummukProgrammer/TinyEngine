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

	IRenderObjectPtr Render::AddRenderObject(const IRenderObjectBuilder & builder)
	{
		auto object = builder.GetPtr();
		_objects.push_back(object);
		return object;
	}

	void Render::RemoveRenderObject(IRenderObjectPtr object)
	{
		const auto it = GetConstObjectIterator(object);
		if (it != _objects.end())
		{
			_objects.erase(it);
		}
	}

	bool Render::HasRenderObject(IRenderObjectPtr object) const
	{
		return GetConstObjectIterator(object) != _objects.end();
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
		_renderWindowPtr.reset();

		return *this;
	}

	void Render::UpdateObjects(float deltaTime)
	{
		for (const auto& object : _objects)
		{
			object->Update(deltaTime);
		}
	}

	void Render::DrawObjects()
	{
		for (const auto& object : _objects)
		{
			_renderWindowPtr->Draw(object.get());
		}
	}

	void Render::CreateWindow(IRenderWindowPtr window, const RenderWindowSettings& windowSettings)
	{
		_renderWindowPtr = window;
		_renderWindowPtr->Create(windowSettings);
	}

	Render::ObjectsList::const_iterator Render::GetConstObjectIterator(IRenderObjectPtr object) const
	{
		return std::find(_objects.begin(), _objects.end(), object);
	}
}
