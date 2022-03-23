#include "FpsCounter.hpp"

namespace TinyEngine
{
	void FpsCounter::OnWindowUpdate(float deltaTime)
	{
		if (_timerFpsCounter <= 0.f)
		{
			// Таймер истёк, получаем актуальное кол-во Fps.
			_lastFpsCounter = static_cast<unsigned>(1.f / deltaTime);
			_timerFpsCounter = _delayFpsCounter;
		}
		else
		{
			// Продолжаем отнимать значение таймера.
			_timerFpsCounter -= deltaTime;

			if (_timerFpsCounter < 0.f)
			{
				_timerFpsCounter = 0.f;
			}
		}
	}
}
