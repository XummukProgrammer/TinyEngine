#include "States.hpp"

#include <TinyEngine/Core/States/State.hpp>

namespace TinyEngine
{
	void States::OnInit()
	{
		for (const auto& [ id, state ] : _states)
		{
			state->SetStates(this);
			state->SetStateId(id);
			state->OnInit();
		}

		ChangeState(_startStateId);
	}

	void States::OnDeinit()
	{
		for (const auto& [ id, state ] : _states)
		{
			state->OnDeinit();
		}
	}

	void States::OnUpdate()
	{
		auto it = _states.find(_currentStateId);
		if (it != _states.end())
		{
			it->second->OnUpdate();

			const auto& newStateId = it->second->GetNewStateId();
			if (!newStateId.empty())
			{
				ChangeState(newStateId);
			}
		}
	}

	void States::ChangeState(std::string_view stateId)
	{
		if (auto it = _states.find(_currentStateId); it != _states.end())
		{
			it->second->OnExit();
		}

		const auto prevStateId = _currentStateId;
		_currentStateId = stateId;

		if (auto it = _states.find(_currentStateId); it != _states.end())
		{
			it->second->SetPrevStateId(prevStateId);
			it->second->OnEnter();
		}
	}
}
