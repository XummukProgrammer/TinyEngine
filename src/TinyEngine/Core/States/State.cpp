#include "State.hpp"

#include <TinyEngine/Core/States/States.hpp>
#include <TinyEngine/Core/States/StateTransition.hpp>

namespace TinyEngine
{
	void State::OnInit()
	{
		for (const auto& transition : _transitions)
		{
			transition->OnInit();
		}
	}

	bool State::IsActive() const
	{
		return _states->GetCurrentStateId() == GetStateId();
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
				if ((_prevStateId == transition->GetPrevStateId()) && transition->CanChangeState())
				{
					return transition;
				}
			}
		}
		return nullptr;
	}
}
