#include "EventSubscriber.hpp"

#include <TinyEngine/Event/Event.hpp>

namespace TinyEngine
{
	EventSubscriber::EventSubscriber(const Callback& callback)
		: _callback(callback)
	{
	}

	EventSubscriberSharedPtr EventSubscriber::Create(const Callback& callback)
	{
		auto subscriber = std::make_shared<EventSubscriber>(callback);
		return subscriber;
	}

	void EventSubscriber::Call(EventPtr event)
	{
		if (_callback)
		{
			_callback(event);
		}
	}
}
