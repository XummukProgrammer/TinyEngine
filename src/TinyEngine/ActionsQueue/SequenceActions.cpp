#include "SequenceActions.hpp"

namespace TinyEngine
{
	void SequenceActions::OnExecute()
	{ 
		if (_actionsQueue.empty())
		{
			return;
		}

		auto& front = _actionsQueue.front();

		if (front->IsExecute())
		{
			front->OnExecute();

			if (front->IsExecuted())
			{
				_actionsQueue.pop();
			}
		}
	}

	bool SequenceActions::IsExecuted() const
	{
		return _actionsQueue.empty();
	}

	void SequenceActions::AddAction(IActionPtr&& action)
	{ 
		_actionsQueue.push(std::move(action));
	}
}
