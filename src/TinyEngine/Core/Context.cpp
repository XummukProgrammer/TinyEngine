#include "Context.hpp"

#include <TinyEngine/Core/FileSystem.hpp>
#include <TinyEngine/Properties/Properties.hpp>
#include <TinyEngine/Core/Factory.hpp>
#include <TinyEngine/Level/Level.hpp>

namespace TinyEngine::Core
{
	const std::string IO_PROPERTIES_FILE_PATH = "io_properties.xml";

	Context::Context()
		: _fileSystem(std::make_shared<FileSystem>())
		, _sessionProperties(std::make_shared<Properties::Properties>())
		, _IOProperties(std::make_shared<Properties::XmlProperties>())
		, _factory(std::make_shared<Factory>())
		, _level(std::make_shared<Level::Level>())
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
	}

	void Context::OnInit()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onInitCallback)
		{
			_onInitCallback(sharedThis);
		}

		_level->OnInit(sharedThis);
	}

	void Context::OnDeinit()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onDeinitCallback)
		{
			_onDeinitCallback(sharedThis);
		}

		_level->OnDeinit(sharedThis);
	}

	void Context::OnUpdate()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onUpdateCallback)
		{
			_onUpdateCallback(sharedThis);
		}

		_level->OnUpdate(sharedThis);
	}

	void Context::OnDraw()
	{ 
		auto&& sharedThis = shared_from_this();

		if (_onDrawCallback)
		{
			_onDrawCallback(sharedThis);
		}

		_level->OnDraw(sharedThis);
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

	Context::FileSystemPtr Context::GetFileSystem() const
	{
		return _fileSystem;
	}

	Context::PropertiesPtr Context::GetSessionProperties() const
	{
		return _sessionProperties;
	}

	Context::FactoryPtr Context::GetFactory() const
	{
		return _factory;
	}

	Context::LevelPtr Context::GetLevel() const
	{
		return _level;
	}

	Context::EntityPtr Context::CreateEntity()
	{
		return _level->CreateEntity(shared_from_this());
	}

	void Context::AddEntity(const EntityPtr& entity)
	{ 
		_level->AddEntity(entity);
	}

	void Context::AddScene(const ScenePtr& scene)
	{ 
		_level->AddScene(shared_from_this(), scene);
	}

	void Context::SetCurrentScene(const ScenePtr& scene)
	{ 
		_level->SetCurrentScene(scene);
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
