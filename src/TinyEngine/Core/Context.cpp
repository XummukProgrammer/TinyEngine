#include "Context.hpp"

#include <TinyEngine/Properties/PropertiesData.hpp>
#include <TinyEngine/Level/LevelManager.hpp>
#include <TinyEngine/Level/Entity.hpp>
#include <TinyEngine/Level/Scene.hpp>
#include <TinyEngine/Render/RenderManager.hpp>
#include <TinyEngine/Core/Window.hpp>

namespace TinyEngine::Core
{
	const std::string IO_PROPERTIES_FILE_PATH = "io_properties.xml";

	Context::Context()
		: _sessionProperties(std::make_shared<Properties::PropertiesData>())
		, _IOProperties(std::make_shared<Properties::XmlPropertiesData>())
	{ 
	}

	void Context::OnPreInit()
	{ 
		if (_onPreInitCallback)
		{
			_onPreInitCallback();
		}

		Level::LevelManager::GetInstance().OnPreInit();
		Render::RenderManager::GetInstance().OnPreInit();
	}

	void Context::OnInit()
	{ 
		if (_onInitCallback)
		{
			_onInitCallback();
		}

		Level::LevelManager::GetInstance().OnInit();
		Render::RenderManager::GetInstance().OnInit();
	}

	void Context::OnDeinit()
	{ 
		if (_onDeinitCallback)
		{
			_onDeinitCallback();
		}

		Level::LevelManager::GetInstance().OnDeinit();
		Render::RenderManager::GetInstance().OnDeinit();
	}

	void Context::OnUpdate()
	{ 
		if (_onUpdateCallback)
		{
			_onUpdateCallback();
		}

		Level::LevelManager::GetInstance().OnUpdate();
		Render::RenderManager::GetInstance().OnUpdate();
	}

	void Context::OnDraw()
	{ 
		if (_onDrawCallback)
		{
			_onDrawCallback();
		}

		Level::LevelManager::GetInstance().OnDraw();
		Render::RenderManager::GetInstance().OnDraw();
	}

	void Context::OnEvent()
	{ 
		if (_onEventCallback)
		{
			_onEventCallback();
		}

		Level::LevelManager::GetInstance().OnEvent();
	}

	Context::PropertiesDataPtr Context::GetSessionProperties() const
	{
		return _sessionProperties;
	}

	Context::XmlPropertiesDataPtr Context::GetIOProperties() const
	{
		return _IOProperties;
	}

	std::string Context::GetIOPropertiesPath() const
	{
		return IO_PROPERTIES_FILE_PATH;
	}
}
