#ifndef _SUBSCRIBER_HEADER_
#define _SUBSCRIBER_HEADER_

#include <TinyEngine/Data/CounterRef.hpp>

#include <functional>

namespace TinyEngine
{
	// Идентификатор подписчика.
	using SubscriberIndex = unsigned;

	/*
		Класс подписывается на событие и вызывает обработчик при отправке события.
	*/
	template<typename TEvent>
	class Subscriber final : public CounterRef<Subscriber<TEvent>, SubscriberIndex>
	{
	public:
		using DefaultHandler = std::function<void(TEvent&)>;

	public:
		Subscriber() = default;
		~Subscriber() = default;

	public:
		static Subscriber<TEvent> GetEmpty();

	public:
		// Произошла отправка события.
		void OnSend(TEvent& params);

	public:
		void SetSendHandler(const DefaultHandler& handler) { _sendHandler = handler; }

	private:
		// Обработчик при отправке события.
		DefaultHandler _sendHandler;
	};

	template<typename TEvent>
	Subscriber<TEvent> Subscriber<TEvent>::GetEmpty()
	{
		static Subscriber<TEvent> subscriber;
		return subscriber;
	}

	template<typename TEvent>
	void Subscriber<TEvent>::OnSend(TEvent& params)
	{ 
		if (_sendHandler)
		{
			_sendHandler(params);
		}
	}
}

#endif // _SUBSCRIBER_HEADER_
