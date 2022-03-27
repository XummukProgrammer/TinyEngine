#include "ActionsQueue.hpp"

namespace TinyEngine
{
	void ActionsQueue::OnWindowUpdated()
	{ 
		if (_actionsQueue.empty())
		{
			return;
		}

		auto& front = _actionsQueue.front();

		if (front->IsExecute())
		{
			front->OnExecute();

			_actionsQueue.pop();
		}
	}

	void ActionsQueue::AddAction(IActionPtr&& action)
	{
		_actionsQueue.push(std::move(action));
	}
}
