#include "ActionsQueueContainer.hpp"

namespace TinyEngine
{
	void ActionsQueueContainer::OnWindowUpdated()
	{ 
		if (_actionsQueue.IsEmpty())
		{
			return;
		}

		const auto& front = _actionsQueue.Front();

		if (front->IsExecute())
		{
			front->OnExecute();

			if (front->IsExecuted())
			{
				_actionsQueue.Pop();
			}
		}
	}

	void ActionsQueueContainer::AddAction(IActionPtr&& action)
	{ 
		_actionsQueue.Push(std::move(action));
	}

	std::vector<std::string> ActionsQueueContainer::GetActionsIds() const
	{
		std::vector<std::string> actionsIds;

		for (const auto& action : _actionsQueue.ToVector())
		{
			actionsIds.push_back(action->GetId());

			if (auto containerAction = dynamic_cast<ActionsQueueContainer*>(action.get()))
			{
				auto&& sequenceActionsIds = containerAction->GetActionsIds();
				actionsIds.insert(actionsIds.end(), sequenceActionsIds.begin(), sequenceActionsIds.end());
			}
		}

		return actionsIds;
	}
}
