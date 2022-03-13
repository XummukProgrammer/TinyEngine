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
		auto&& sharedThis = shared_from_this();

		if (_onPreInitCallback)
		{
			_onPreInitCallback(sharedThis);
		}

		Level::Level::GetInstance().OnPreInit(sharedThis);
		Render::Render::GetInstance().OnPreInit(sharedThis);
	}

	void Context::OnInit()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onInitCallback)
		{
			_onInitCallback(sharedThis);
		}

		Level::Level::GetInstance().OnInit(sharedThis);
		Render::Render::GetInstance().OnInit(sharedThis);
	}

	void Context::OnDeinit()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onDeinitCallback)
		{
			_onDeinitCallback(sharedThis);
		}

		Level::Level::GetInstance().OnDeinit(sharedThis);
		Render::Render::GetInstance().OnDeinit(sharedThis);
	}

	void Context::OnUpdate()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onUpdateCallback)
		{
			_onUpdateCallback(sharedThis);
		}

		Level::Level::GetInstance().OnUpdate(sharedThis);
		Render::Render::GetInstance().OnUpdate(sharedThis);
	}

	void Context::OnDraw()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onDrawCallback)
		{
			_onDrawCallback(sharedThis);
		}

		Level::Level::GetInstance().OnDraw(sharedThis);
		Render::Render::GetInstance().OnDraw(sharedThis);
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
