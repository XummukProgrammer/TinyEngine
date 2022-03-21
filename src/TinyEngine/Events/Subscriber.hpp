﻿#ifndef _SUBSCRIBER_HEADER_
#define _SUBSCRIBER_HEADER_

#include <functional>

namespace TinyEngine
{
	using SubscriberIndex = unsigned;

	template<typename TEvent>
	class Subscriber final
	{
	public:
		using DefaultHandler = std::function<void(TEvent&)>;

	public:
		Subscriber() = default;
		~Subscriber() = default;

	public:
		static Subscriber<TEvent> GetEmpty();

	public:
		void OnSend(TEvent& params);

	public:
		void SetSendHandler(const DefaultHandler& handler) { _sendHandler = handler; }

	public:
		void SetIndex(SubscriberIndex index) { _index = index; }
		SubscriberIndex GetIndex() const { return _index; }

	private:
		DefaultHandler _sendHandler;
		SubscriberIndex _index;
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
