#ifndef _FPS_COUNTER_HEADER_
#define _FPS_COUNTER_HEADER_

#include <TinyEngine/Core/Timer.hpp>

namespace TinyEngine
{
	// Класс работает с счётчиком FPS, обновляя его используя deltaTime раз в секунду.
	class FpsCounter final
	{
	public:
		FpsCounter();
		~FpsCounter() = default;

	public:
		// Окно обновилось.
		void OnWindowUpdate();

	public:
		// Получить счётчик Fps.
		unsigned GetFpsCounter() const { return _lastFpsCounter; }

	private:
		// Запустить таймер.
		void StartTimer();

	private:
		void OnExpired(TimerExpiredEventParameters& params);

	private:
		// Последнее значения счётчика Fps.
		unsigned _lastFpsCounter = 0;
		// Таймер для обновления значения счётчика Fps.
		Timer _timer;
	};
}

#endif // _FPS_COUNTER_HEADER_
