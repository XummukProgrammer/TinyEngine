#include "ActionsQueueContainer.hpp"

namespace TinyEngine
{
	void ActionsQueueContainer::OnWindowUpdated()
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

	void ActionsQueueContainer::AddAction(IActionPtr && action)
	{ 
		_actionsQueue.push(std::move(action));
	}
}
