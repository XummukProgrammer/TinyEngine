#include "Context.hpp"

#include <TinyEngine/Properties/Properties.hpp>
#include <TinyEngine/Level/Level.hpp>
#include <TinyEngine/Level/Entity.hpp>
#include <TinyEngine/Level/Scene.hpp>
#include <TinyEngine/Render/Render.hpp>

namespace TinyEngine::Core
{
	const std::string IO_PROPERTIES_FILE_PATH = "io_properties.xml";

	Context::Context()
		: _sessionProperties(std::make_shared<Properties::Properties>())
		, _IOProperties(std::make_shared<Properties::XmlProperties>())
		, _level(std::make_shared<Level::Level>())
		, _render(std::make_shared<Render::Render>())
	{ 
	}

	void Context::OnPreInit()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onPreInitCallback)
		{
			_onPreInitCallback(sharedThis);
		}

		_level->OnPreInit(sharedThis);
		_render->OnPreInit(sharedThis);
	}

	void Context::OnInit()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onInitCallback)
		{
			_onInitCallback(sharedThis);
		}

		_level->OnInit(sharedThis);
		_render->OnInit(sharedThis);
	}

	void Context::OnDeinit()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onDeinitCallback)
		{
			_onDeinitCallback(sharedThis);
		}

		_level->OnDeinit(sharedThis);
		_render->OnDeinit(sharedThis);
	}

	void Context::OnUpdate()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onUpdateCallback)
		{
			_onUpdateCallback(sharedThis);
		}

		_level->OnUpdate(sharedThis);
		_render->OnUpdate(sharedThis);
	}

	void Context::OnDraw()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onDrawCallback)
		{
			_onDrawCallback(sharedThis);
		}

		_level->OnDraw(sharedThis);
		_render->OnDraw(sharedThis);
	}

	void Context::OnEvent()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onEventCallback)
		{
			_onEventCallback(sharedThis);
		}

		_level->OnEvent(sharedThis);
	}

	Context::PropertiesPtr Context::GetSessionProperties() const
	{
		return _sessionProperties;
	}

	Context::RenderPtr Context::GetRender() const
	{
		return _render;
	}

	Context::EntityPtr Context::CreateEntity()
	{
		return _level->CreateEntity(shared_from_this());
	}

	void Context::AddEntity(const EntityPtr& entity)
	{ 
		_level->AddEntity(entity);
	}

	void Context::RemoveEntity(const EntityPtr& entity)
	{ 
		entity->Remove();
	}

	void Context::RemoveEntities()
	{ 
		_level->RemoveEntities();
	}

	void Context::AddScene(std::string_view key, const ScenePtr& scene)
	{ 
		_level->AddScene(shared_from_this(), key, scene);
	}

	void Context::SetCurrentScene(const ScenePtr& scene)
	{ 
		_level->SetCurrentScene(scene);
	}

	Context::ScenePtr Context::GetCurrentScene() const
	{
		return _level->GetCurrentScene();
	}

	Context::ScenePtr Context::GetScene(std::string_view key) const
	{
		return _level->GetScene(key);
	}

	void Context::RemoveScenes()
	{ 
		_level->RemoveScenes();
	}

	Context::XmlPropertiesPtr Context::GetIOProperties() const
	{
		return _IOProperties;
	}

	void Context::IOPropertiesSaveToFile()
	{ 
		_IOProperties->SaveToFile(shared_from_this(), IO_PROPERTIES_FILE_PATH);
	}

	void Context::IOPropertiesLoadFromFile()
	{ 
		_IOProperties->LoadFromFile(shared_from_this(), IO_PROPERTIES_FILE_PATH);
	}
}
