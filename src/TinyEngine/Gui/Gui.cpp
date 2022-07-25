#include "Gui.hpp"

namespace TinyEngine
{
	void Gui::Init(IRenderWindowPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Init(renderWindowPtr);
		}
	}

	void Gui::ExtractEvents(IRenderWindowPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->ExtractEvents(renderWindowPtr);
		}
	}

	void Gui::Update(float deltaTime, IRenderWindowPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Update(deltaTime, renderWindowPtr);
		}
	}

	void Gui::Draw(float deltaTime, IRenderWindowPtr renderWindowPtr)
	{
		_container.Draw(deltaTime, renderWindowPtr);
	}

	void Gui::Display(IRenderWindowPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Display(renderWindowPtr);
		}
	}

	void Gui::Shutdown(IRenderWindowPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Shutdown(renderWindowPtr);
		}
	}
}
