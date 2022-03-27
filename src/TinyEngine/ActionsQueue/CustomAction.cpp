#include "CustomAction.hpp"

namespace TinyEngine
{
	bool CustomAction::IsExecute() const
	{
		return _isExecuteCallback ? _isExecuteCallback() : true;
	}

	void CustomAction::OnExecute()
	{ 
		if (_onExecuteCallback)
		{
			_onExecuteCallback();
		}
	}
}
