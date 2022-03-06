#include "Context.hpp"

#include <TinyEngine/Core/FileSystem.hpp>

namespace TinyEngine::Core
{
	Context::Context()
		: _fileSystem(std::make_shared<FileSystem>())
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
}
