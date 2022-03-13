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

		Level::Level::GetInstance().OnPreInit(sharedThis);
		_render->OnPreInit(sharedThis);
	}

	void Context::OnInit()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onInitCallback)
		{
			_onInitCallback(sharedThis);
		}

		Level::Level::GetInstance().OnInit(sharedThis);
		_render->OnInit(sharedThis);
	}

	void Context::OnDeinit()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onDeinitCallback)
		{
			_onDeinitCallback(sharedThis);
		}

		Level::Level::GetInstance().OnDeinit(sharedThis);
		_render->OnDeinit(sharedThis);
	}

	void Context::OnUpdate()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onUpdateCallback)
		{
			_onUpdateCallback(sharedThis);
		}

		Level::Level::GetInstance().OnUpdate(sharedThis);
		_render->OnUpdate(sharedThis);
	}

	void Context::OnDraw()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onDrawCallback)
		{
			_onDrawCallback(sharedThis);
		}

		Level::Level::GetInstance().OnDraw(sharedThis);
		_render->OnDraw(sharedThis);
	}

	void Context::OnEvent()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onEventCallback)
		{
			_onEventCallback(sharedThis);
		}

		Level::Level::GetInstance().OnEvent(sharedThis);
	}

	Context::PropertiesPtr Context::GetSessionProperties() const
	{
		return _sessionProperties;
	}

	Context::RenderPtr Context::GetRender() const
	{
		return _render;
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
