#ifndef _EVENT_SENDER_HEADER_
#define _EVENT_SENDER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <list>

namespace TinyEngine
{
	class EventSender final
	{
	public:
		EventSender() = default;
		~EventSender() = default;

	public:
		void AddSubscriber(EventSubscriberSharedPtr subscriber);
		bool HasSubscriber(EventSubscriberSharedPtr subscriber) const;
		void RemoveSubscriber(EventSubscriberSharedPtr subscriber);
		void Send(EventPtr event);

	private:
		std::list<EventSubscriberSharedPtr> _subscribers;
	};
}

#endif // _EVENT_SENDER_HEADER_
