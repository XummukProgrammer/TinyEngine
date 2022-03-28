#include "FpsCounter.hpp"

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
	FpsCounter::FpsCounter()
	{ 
		_timer.SubscribeExpired(std::bind(&FpsCounter::OnExpired, this, std::placeholders::_1));

		StartTimer();
	}

	void FpsCounter::OnWindowUpdate()
	{
		_timer.OnWindowUpdate();
	}

	void FpsCounter::StartTimer()
	{ 
		_timer.SetTime(1.f);
		_timer.Start();
	}

	void FpsCounter::OnExpired(TimerExpiredEventParameters& params)
	{ 
		const float deltaTime = Application::GetInstance().GetConstWindow().GetDeltaTime();

		_lastFpsCounter = static_cast<unsigned>(1.f / deltaTime);

		StartTimer();
	}
}
