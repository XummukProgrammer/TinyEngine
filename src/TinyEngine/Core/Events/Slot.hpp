#ifndef _SLOT_HEADER_
#define _SLOT_HEADER_

#include <functional>

namespace TinyEngine
{
	template<typename ... Args>
	class Signal;

	template<typename ... Args>
	class Slot final
	{
	public:
		using Callback = std::function<void(Args ...)>;

	public:
		Slot(const Callback& callback);
		~Slot() = default;

	public:
		void Call(Args ... args);

	private:
		void Init(const Callback& callback);

	private:
		Callback _callback;
	};

	template<typename ... Args>
	Slot<Args...>::Slot(const Callback& callback)
	{
		Init(callback);
	}

	template<typename ... Args>
	void Slot<Args ...>::Call(Args ...args)
	{
		if (_callback)
		{
			_callback(std::forward<Args>(args)...);
		}
	}

	template<typename ... Args>
	void Slot<Args...>::Init(const Callback& callback)
	{
		_callback = callback;
	}
}

#endif // _SLOT_HEADER_
