#ifndef _FPS_COUNTER_HEADER_
#define _FPS_COUNTER_HEADER_

namespace TinyEngine
{
	// Класс работает с счётчиком FPS, обновляя его используя deltaTime раз в секунду.
	class FpsCounter final
	{
	public:
		FpsCounter() = default;
		~FpsCounter() = default;

	public:
		// Окно обновилось.
		void OnWindowUpdate(float deltaTime);

	public:
		// Получить счётчик Fps.
		unsigned GetFpsCounter() const { return _lastFpsCounter; }

	private:
		// Последнее значения счётчика FPS.
		unsigned _lastFpsCounter = 0;
		// Сколько осталось времени до обновления счётчика Fps.
		float _timerFpsCounter = 0.f;
		// Задержка перед обновлением счётчика Fps.
		const float _delayFpsCounter = 1.f;
	};
}

#endif // _FPS_COUNTER_HEADER_
