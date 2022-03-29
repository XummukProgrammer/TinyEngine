#ifndef _TIMER_HEADER_
#define _TIMER_HEADER_

#include <TinyEngine/Events/Publisher.hpp>

namespace TinyEngine
{
	class TimerExpiredEventParameters final : public EventParameters
	{
	public:
		TimerExpiredEventParameters() = default;
		~TimerExpiredEventParameters() = default;
	};

	class Timer final
	{
		DECLARE_EVENT(TimerExpiredEventParameters, Expired)

	public:
		Timer() = default;
		~Timer();

	public:
		void OnWindowUpdate();

		bool IsStarted() const { return _isStarted; }
		bool IsExpired() const { return _time <= 0.f; }
		
		void SetIsLooped(bool isLooped) { _isLooped = isLooped; }
		bool IsLooped() const { return _isLooped; }

		void SetMaxTime(float maxTime) { _maxTime = maxTime; }
		float GetMaxTime() const { return _maxTime; }

	public:
		void Start();
		void Stop() { _isStarted = false; }

	private:
		void _OnExpired();

	private:
		// Текущее время таймера.
		float _time = 0.f;
		// Максимальное время (Будет установлено при запуске таймера).
		float _maxTime = 0.f;
		// Запущен ли таймер?
		bool _isStarted = false;
		// Зациклен ли таймер?
		bool _isLooped = false;
	};
}

#endif // _TIMER_HEADER_
