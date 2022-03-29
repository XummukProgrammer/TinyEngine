#include "FpsCounter.hpp"

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
	void FpsCounter::StartTimer()
	{ 
		auto timer = std::make_unique<Timer>();
		timer->SubscribeExpired(std::bind(&FpsCounter::OnExpired, this, std::placeholders::_1));
		timer->SetMaxTime(1.f);
		timer->SetIsLooped(true);
		timer->Start();

		Application::GetInstance().GetTimers().AddTimer(std::move(timer));
	}

	void FpsCounter::OnExpired(TimerExpiredEventParameters& params)
	{ 
		const float deltaTime = Application::GetInstance().GetConstWindow().GetDeltaTime();

		_lastFpsCounter = static_cast<unsigned>(1.f / deltaTime);
	}
}
