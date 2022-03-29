#ifndef _TIMERS_HEADER_
#define _TIMERS_HEADER_

#include <TinyEngine/Core/Timer.hpp>

#include <memory>
#include <vector>

namespace TinyEngine
{
	class Timers final
	{
	public:
		using TimerPtr = std::unique_ptr<Timer>;

	public:
		Timers() = default;
		~Timers() = default;

	public:
		void OnWindowUpdate();

	public:
		void AddTimer(TimerPtr&& timer);

	private:
		std::vector<TimerPtr> _timers;
	};
}

#endif // _TIMERS_HEADER_
