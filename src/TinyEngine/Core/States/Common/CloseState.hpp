#ifndef _CLOSE_STATE_HEADER_
#define _CLOSE_STATE_HEADER_

#include <TinyEngine/Core/States/State.hpp>

namespace TinyEngine
{
	class CloseState final : public State
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(CloseState, State)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		CloseState() = default;
		~CloseState() = default;

	public:
		void OnEnter() override;
	};
}

#endif // _CLOSE_STATE_HEADER_
