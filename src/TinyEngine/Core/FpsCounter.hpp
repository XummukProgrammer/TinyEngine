#ifndef _FPS_COUNTER_HEADER_
#define _FPS_COUNTER_HEADER_

#include <TinyEngine/Core/Timer.hpp>

namespace TinyEngine
{
	// Класс работает с счётчиком FPS, обновляя его используя deltaTime раз в секунду.
	class FpsCounter final
	{
	public:
		FpsCounter() = default;
		~FpsCounter() = default;

	public:
		// Получить счётчик Fps.
		unsigned GetFpsCounter() const { return _lastFpsCounter; }

		// Запустить таймер.
		void StartTimer();

	private:
		void OnExpired(TimerExpiredEventParameters& params);

	private:
		// Последнее значения счётчика Fps.
		unsigned _lastFpsCounter = 0;
	};
}

#endif // _FPS_COUNTER_HEADER_
