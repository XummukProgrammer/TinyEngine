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

	public:
		void SetTime(float time) { _time = time; }
		float GetTime() const { return _time; }

		bool IsStarted() const { return _isStarted; }
		bool IsExpired() const { return GetTime() <= 0.f; }
		
	public:
		void Start() { _isStarted = true; }
		void Stop() { _isStarted = false; }

	private:
		void _OnExpired();

	private:
		// Текущее время таймера.
		float _time = 0.f;
		// Запущен ли таймер?
		bool _isStarted = false;
	};
}

#endif // _TIMER_HEADER_
