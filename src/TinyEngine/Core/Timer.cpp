#include "Timer.hpp"

#include <TinyEngine/Core/Core.hpp>

namespace TinyEngine
{
	Timer::~Timer()
	{ 
		UnsubscribeAllExpired();
	}

	void Timer::OnWindowUpdate()
	{
		if (!IsStarted())
		{
			return;
		}

		if (IsExpired())
		{
			_OnExpired();
			return;
		}

		const float deltaTime = Core::GetApplication().GetConstWindow().GetDeltaTime();

		_time -= deltaTime;
	}

	void Timer::_OnExpired()
	{
		Stop();

		TimerExpiredEventParameters params;
		OnExpired(params);
	}
}
