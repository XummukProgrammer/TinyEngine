#ifndef _STATE_TRANSITION_HEADER_
#define _STATE_TRANSITION_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

#include <string>

namespace TinyEngine
{
	class StateTransition : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(StateTransition)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_prevStateId, "PrevStateID", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_nextStateId, "NextStateID", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		StateTransition() = default;
		virtual ~StateTransition() = default;

	public:
		const std::string& GetPrevStateId() const { return _prevStateId; }
		const std::string& GetNextStateId() const { return _nextStateId; }

	public:
		virtual void OnInit() {}
		virtual bool CanChangeState() const { return false; }

	private:
		std::string _prevStateId;
		std::string _nextStateId;
	};
}

#endif // _STATE_TRANSITION_HEADER_
