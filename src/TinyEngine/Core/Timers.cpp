#include "Timers.hpp"

namespace TinyEngine
{
	void Timers::OnWindowUpdate()
	{ 
		for (auto it = _timers.begin(); it != _timers.end();)
		{
			auto& timer = *it;

			timer->OnWindowUpdate();

			bool isTimerDestroy = false;

			if (timer->IsExpired() && !timer->IsStarted())
			{
				if (timer->IsLooped())
				{
					timer->Start();
				}
				else
				{
					isTimerDestroy = true;
				}
			}

			if (isTimerDestroy)
			{
				it = _timers.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	void Timers::AddTimer(TimerPtr&& timer)
	{ 
		_timers.push_back(std::move(timer));
	}
}
