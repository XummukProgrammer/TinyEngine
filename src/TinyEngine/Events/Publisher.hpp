#ifndef _PUBLISHER_HEADER_
#define _PUBLISHER_HEADER_

#include "Subscriber.hpp"
#include "Event.hpp"

#include <map>
#include <queue>

namespace TinyEngine
{
	template<typename TEvent>
	class Publisher final
	{
	public:
		using SubscriberPtr = Subscriber<TEvent>*;
		using SubscriberRef = Subscriber<TEvent>&;
		using SubscriberHandler = typename Subscriber<TEvent>::DefaultHandler;

	public:
		Publisher() = default;
		~Publisher() = default;

	public:
		SubscriberRef CreateSubscriber(const SubscriberHandler& handler);
		void DestroySubscriber(SubscriberIndex subscriberIndex);
		bool HasSubscriber(SubscriberIndex subscriberIndex) const;

		void SendEvent(TEvent& event);

	private:
		void ForceDestroySubscriber(SubscriberIndex subscriberIndex);
		void DestroySubscribersFromQueue();

	private:
		std::map<SubscriberIndex, SubscriberPtr> _subscribers;
		SubscriberIndex _lastSubscriberIndex = 0;
		bool _isSendEvent = false;
		std::queue<SubscriberIndex> _destroySubscribersQueue;
	};

	template<typename TEvent>
	typename Publisher<TEvent>::SubscriberRef Publisher<TEvent>::CreateSubscriber(const SubscriberHandler& handler)
	{
		auto subscriber = new Subscriber<TEvent>();
		subscriber->SetSendHandler(handler);
		subscriber->SetIndex(_lastSubscriberIndex);

		_subscribers[_lastSubscriberIndex] = subscriber;

		++_lastSubscriberIndex;

		return *subscriber;
	}

	template<typename TEvent>
	void Publisher<TEvent>::DestroySubscriber(SubscriberIndex subscriberIndex)
	{ 
		if (_isSendEvent)
		{
			_destroySubscribersQueue.push(subscriberIndex);
		}
		else
		{
			ForceDestroySubscriber(subscriberIndex);
		}
	}

	template<typename TEvent>
	bool Publisher<TEvent>::HasSubscriber(SubscriberIndex subscriberIndex) const
	{ 
		return _subscribers.find(subscriberIndex) != _subscribers.end();
	}

	template<typename TEvent>
	void Publisher<TEvent>::SendEvent(TEvent& event)
	{ 
		_isSendEvent = true;

		for (const auto& [ index, subscriber ] : _subscribers)
		{
			subscriber->OnSend(event);
		}

		_isSendEvent = false;

		DestroySubscribersFromQueue();
	}
	
	template<typename TEvent>
	void Publisher<TEvent>::ForceDestroySubscriber(SubscriberIndex subscriberIndex)
	{ 
		auto it = _subscribers.find(subscriberIndex);

		if (it != _subscribers.end())
		{
			_subscribers.erase(it);
		}
	}

	template<typename TEvent>
	void Publisher<TEvent>::DestroySubscribersFromQueue()
	{ 
		while (!_destroySubscribersQueue.empty())
		{
			auto& frontQueue = _destroySubscribersQueue.front();

			ForceDestroySubscriber(frontQueue);

			_destroySubscribersQueue.pop();
		}
	}
}

#endif // _PUBLISHER_HEADER_
