#ifndef _PUBLISHER_HEADER_
#define _PUBLISHER_HEADER_

#include "Subscriber.hpp"
#include "EventParameters.hpp"

#include <map>
#include <queue>
#include <memory>

namespace TinyEngine
{
	template<typename TEvent>
	class Publisher final
	{
	public:
		using SubscriberPtr = std::unique_ptr<Subscriber<TEvent>>;
		using SubscriberRef = Subscriber<TEvent>&;
		using SubscriberHandler = typename Subscriber<TEvent>::DefaultHandler;

	public:
		Publisher() = default;
		~Publisher() = default;

	public:
		SubscriberIndex Subscribe(const SubscriberHandler& handler);
		void Unsubscribe(SubscriberIndex subscriberIndex);
		bool HasSubscriber(SubscriberIndex subscriberIndex) const;

		void Send(TEvent& params);

	private:
		void ForceDestroySubscriber(SubscriberIndex subscriberIndex);
		void DestroySubscribersFromQueue();

	private:
		std::map<SubscriberIndex, SubscriberPtr> _subscribers;
		SubscriberIndex _lastSubscriberIndex = 0;
		bool _isSendProcess = false;
		std::queue<SubscriberIndex> _destroySubscribersQueue;
	};

	template<typename TEvent>
	typename SubscriberIndex Publisher<TEvent>::Subscribe(const SubscriberHandler& handler)
	{
		SubscriberIndex index = _lastSubscriberIndex;
		++_lastSubscriberIndex;

		auto subscriber = std::make_unique<Subscriber<TEvent>>();
		subscriber->SetSendHandler(handler);
		subscriber->SetIndex(index);

		_subscribers[index] = std::move(subscriber);

		return index;
	}

	template<typename TEvent>
	void Publisher<TEvent>::Unsubscribe(SubscriberIndex subscriberIndex)
	{ 
		if (_isSendProcess)
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
	void Publisher<TEvent>::Send(TEvent& params)
	{ 
		_isSendProcess = true;

		for (const auto& [ index, subscriber ] : _subscribers)
		{
			subscriber->OnSend(params);
		}

		_isSendProcess = false;

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

#define DECLARE_EVENT(eventParametersClass, eventName) \
	private: \
		using eventName ## Publisher = TinyEngine::Publisher<eventParametersClass>; \
		using eventName ## Subscriber = TinyEngine::Subscriber<eventParametersClass>; \
		eventName ## Publisher _publisher ## eventName; \
	public: \
		TinyEngine::SubscriberIndex Subscribe ## eventName(eventName ## Subscriber::DefaultHandler handler) \
		{ return _publisher ## eventName.Subscribe(handler); } \
		void Unsubscribe ## eventName(TinyEngine::SubscriberIndex subscriberIndex) \
		{ _publisher ## eventName.Unsubscribe(subscriberIndex); } \
	protected: \
		void On ## eventName(eventParametersClass& params) { _publisher ## eventName.Send(params); } \
	public:
		

#endif // _PUBLISHER_HEADER_
