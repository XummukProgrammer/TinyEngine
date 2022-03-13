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
	{ 
	}

	void Context::OnPreInit()
	{ 
		if (_onPreInitCallback)
		{
			_onPreInitCallback();
		}

		Level::Level::GetInstance().OnPreInit();
		Render::Render::GetInstance().OnPreInit();
	}

	void Context::OnInit()
	{ 
		if (_onInitCallback)
		{
			_onInitCallback();
		}

		Level::Level::GetInstance().OnInit();
		Render::Render::GetInstance().OnInit();
	}

	void Context::OnDeinit()
	{ 
		if (_onDeinitCallback)
		{
			_onDeinitCallback();
		}

		Level::Level::GetInstance().OnDeinit();
		Render::Render::GetInstance().OnDeinit();
	}

	void Context::OnUpdate()
	{ 
		if (_onUpdateCallback)
		{
			_onUpdateCallback();
		}

		Level::Level::GetInstance().OnUpdate();
		Render::Render::GetInstance().OnUpdate();
	}

	void Context::OnDraw()
	{ 
		if (_onDrawCallback)
		{
			_onDrawCallback();
		}

		Level::Level::GetInstance().OnDraw();
		Render::Render::GetInstance().OnDraw();
	}

	void Context::OnEvent()
	{ 
		if (_onEventCallback)
		{
			_onEventCallback();
		}

		Level::Level::GetInstance().OnEvent();
	}

	Context::PropertiesPtr Context::GetSessionProperties() const
	{
		return _sessionProperties;
	}

	Context::XmlPropertiesPtr Context::GetIOProperties() const
	{
		return _IOProperties;
	}

	std::string Context::GetIOPropertiesPath() const
	{
		return std::string();
	}
}
