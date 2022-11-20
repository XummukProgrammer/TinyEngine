#ifndef _START_STATE_HEADER_
#define _START_STATE_HEADER_

#include <TinyEngine/Core/States/State.hpp>

namespace TinyEngine
{
	class StartState final : public State
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(StartState, State)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		StartState() = default;
		~StartState() = default;

	public:
		void OnUpdate() override;
		void OnEnter() override;
		void OnExit() override;
	};
}

#endif // _START_STATE_HEADER_
