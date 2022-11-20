#ifndef _STATE_HEADER_
#define _STATE_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/Core/Forwards.hpp>

#include <TinyEngine/Core/States/StateTransition.hpp>

#include <vector>
#include <string>

namespace TinyEngine
{
	class State : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(State)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_transitions, "Transitions", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		State() = default;
		virtual ~State() = default;

	public:
		void SetStates(StatesPtr states) { _states = states; }
		void SetStateId(std::string_view stateId) { _stateId = stateId; }
		void SetPrevStateId(std::string_view prevStateId) { _prevStateId = prevStateId; }

	public:
		virtual void OnInit();
		virtual void OnDeinit() {}
		virtual void OnUpdate() {}
		virtual void OnEnter() {}
		virtual void OnExit() {}

	public:
		bool IsActive() const;

		bool HasQueryToChangeState() const;
		std::string GetNewStateId() const;

	protected:
		const std::string& GetPrevStateId() const { return _prevStateId; }
		const std::string& GetStateId() const { return _stateId; }
		StatesPtr GetStates() const { return _states; }
		StateTransitionSharedPtr GetQueryableTransition() const;

	private:
		StatesPtr _states;
		std::string _stateId;
		std::string _prevStateId;
		std::vector<StateTransitionSharedPtr> _transitions;
	};
}

#endif // _STATE_HEADER_
