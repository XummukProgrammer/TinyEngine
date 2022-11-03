#ifndef _EVENT_SUBSCRIBER_HEADER_
#define _EVENT_SUBSCRIBER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <functional>

namespace TinyEngine
{
	class EventSubscriber final
	{
	public:
		using Callback = std::function<void(EventPtr)>;

	public:
		EventSubscriber(const Callback& callback);
		~EventSubscriber() = default;

	public:
		static EventSubscriberSharedPtr Create(const Callback& callback);

	public:
		void Call(EventPtr event);

	private:
		Callback _callback;
	};
}

#endif // _EVENT_SUBSCRIBER_HEADER_
