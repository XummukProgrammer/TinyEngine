#include "Context.hpp"

#include <TinyEngine/Core/FileSystem.hpp>
#include <TinyEngine/Properties/Properties.hpp>

namespace TinyEngine::Core
{
	const std::string IO_PROPERTIES_FILE_PATH = "io_properties.xml";

	Context::Context()
		: _fileSystem(std::make_shared<FileSystem>())
		, _sessionProperties(std::make_shared<Properties::Properties>())
		, _IOProperties(std::make_shared<Properties::XmlProperties>())
	{ 
	}

	void Context::OnPreInit()
	{ 
		if (_onPreInitCallback)
		{
			_onPreInitCallback(shared_from_this());
		}
	}

	void Context::OnInit()
	{ 
		if (_onInitCallback)
		{
			_onInitCallback(shared_from_this());
		}
	}

	void Context::OnDeinit()
	{ 
		if (_onDeinitCallback)
		{
			_onDeinitCallback(shared_from_this());
		}
	}

	void Context::OnUpdate()
	{ 
		if (_onUpdateCallback)
		{
			_onUpdateCallback(shared_from_this());
		}
	}

	void Context::OnDraw()
	{ 
		if (_onDrawCallback)
		{
			_onDrawCallback(shared_from_this());
		}
	}

	void Context::OnEvent()
	{ 
		if (_onEventCallback)
		{
			_onEventCallback(shared_from_this());
		}
	}

	Context::FileSystemPtr Context::GetFileSystem() const
	{
		return _fileSystem;
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
