#include "EventSender.hpp"

#include <TinyEngine/Event/EventSubscriber.hpp>
#include <TinyEngine/Event/Event.hpp>

namespace TinyEngine
{
	void EventSender::AddSubscriber(EventSubscriberSharedPtr subscriber)
	{
		_subscribers.push_back(subscriber);
	}

	bool EventSender::HasSubscriber(EventSubscriberSharedPtr subscriber) const
	{
		for (const auto& sub : _subscribers)
		{
			if (sub == subscriber)
			{
				return true;
			}
		}
		return false;
	}

	void EventSender::RemoveSubscriber(EventSubscriberSharedPtr subscriber)
	{
		if (HasSubscriber(subscriber))
		{
			_subscribers.remove(subscriber);
		}
	}

	void EventSender::Send(EventPtr event)
	{
		for (const auto& subscriber : _subscribers)
		{
			subscriber->Call(event);
		}
	}
}
