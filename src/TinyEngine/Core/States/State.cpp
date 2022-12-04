#include "State.hpp"

#include <TinyEngine/Core/States/States.hpp>
#include <TinyEngine/Core/States/StateTransition.hpp>

namespace TinyEngine
{
	void State::OnInit()
	{
		for (const auto& transition : _transitions)
		{
			if (transition)
			{
				transition->OnInit();
			}
		}
	}

	bool State::IsActive() const
	{
		if (_states)
		{
			return _states->GetCurrentStateId() == GetStateId();
		}
		return false;
	}

	bool State::HasQueryToChangeState() const
	{
		return GetQueryableTransition() != nullptr;
	}

	std::string State::GetNewStateId() const
	{
		if (auto transition = GetQueryableTransition())
		{
			return transition->GetNextStateId();
		}
		return "";
	}

	StateTransitionSharedPtr State::GetQueryableTransition() const
	{
		if (IsActive())
		{
			for (const auto& transition : _transitions)
			{
				if (transition)
				{
					if ((_prevStateId == transition->GetPrevStateId()) && transition->CanChangeState())
					{
						return transition;
					}
				}
			}
		}
		return nullptr;
	}
}
