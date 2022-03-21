#ifndef _PUBLISHER_HEADER_
#define _PUBLISHER_HEADER_

#include "Subscriber.hpp"
#include "EventParameters.hpp"

#include <map>
#include <queue>
#include <memory>

namespace TinyEngine
{
	/*
		Класс отправляет события, а также даёт возможность подписаться на события.

		TEvent - класс для параметров события.
	*/
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
		// Подписаться на событие.
		SubscriberIndex Subscribe(const SubscriberHandler& handler);
		// Отписаться от события по идентификатору подписчика.
		void Unsubscribe(SubscriberIndex subscriberIndex);
		// Произвести удаление всех подписок на событие.
		void UnsubscribeAll();
		// Проверить есть ли подписчик по его идентификатору.
		bool HasSubscriber(SubscriberIndex subscriberIndex) const;

		/*
			Отправить событие. Все подписчики будут оповещены.

			В том случае, если в какой-либо подписке произойдёт удаление другой подписки,
			то удалённая подписка будет помешена в очередь и будет удалена при завершении метода.
		*/
		void Send(TEvent& params);

	private:
		// Удаление подписчика по его идентификатору, обращается на прямую к хранилищу и удаляет сразу.
		void ForceDestroySubscriber(SubscriberIndex subscriberIndex);
		// Удалить всех подписчиков, которые были удалены во время вызова метода Send.
		void DestroySubscribersFromQueue();

	private:
		// Хранилище подписчиков.
		std::map<SubscriberIndex, SubscriberPtr> _subscribers;
		// Идентификатор последнего подписчика (TODO: Переделать под CounterRef).
		SubscriberIndex _lastSubscriberIndex = 0;
		// Запущен ли процесс по отправке события?
		bool _isSendProcess = false;
		// Очередь, в которую помещаются подписки, которые нужно удалить после того,
		// как будет завершён процесс по отправке события.
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
	void Publisher<TEvent>::UnsubscribeAll()
	{ 
		for (const auto& [ index, subscriber ] : _subscribers)
		{
			Unsubscribe(index);
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

/*
	Создаёт методы в классе для управление событием.
	
	Основные возможности: Подписаться, Отписаться, Удалить все подписки
	и Отправка события (объявлена как protected, нужно обёртывать в публичный метод).
*/
#define DECLARE_EVENT(eventParametersClass, eventName) \
	private: \
		using eventName ## Publisher = TinyEngine::Publisher<eventParametersClass>; \
		using eventName ## Subscriber = TinyEngine::Subscriber<eventParametersClass>; \
		eventName ## Publisher _publisher ## eventName; \
	public: \
		TinyEngine::SubscriberIndex eventName ## _ ## Subscribe(eventName ## Subscriber::DefaultHandler handler) \
		{ return _publisher ## eventName.Subscribe(handler); } \
		void eventName ## _ ## Unsubscribe(TinyEngine::SubscriberIndex subscriberIndex) \
		{ _publisher ## eventName.Unsubscribe(subscriberIndex); } \
		void eventName ## _ ## UnsubscribeAll() \
		{ _publisher ## eventName.UnsubscribeAll(); } \
	protected: \
		void eventName ## _ ## Send(eventParametersClass& params) { _publisher ## eventName.Send(params); } \
	public:
		

#endif // _PUBLISHER_HEADER_
