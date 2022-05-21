#ifndef _TINY_ENGINE_SENDER_HEADER_
#define _TINY_ENGINE_SENDER_HEADER_

#include "Listener.hpp"

#include <functional>
#include <list>

namespace te
{

template<typename TEvent>
class CSender final
{
public:
	using CListenerBase = CListener<TEvent>;
	using CListenerRef = std::reference_wrapper<CListenerBase>;
	using CListenerList = std::list<CListenerRef>;

public:

public:
	CSender() = default;
	~CSender() = default;

public:
	void addListener(const CListenerRef& listenerRef);

	void send(const TEvent& event);

private:
	CListenerList _listenerList;
};

template<typename TEvent>
void CSender<TEvent>::addListener(const CListenerRef& listenerRef)
{ 
	_listenerList.push_back(listenerRef);
}

template<typename TEvent>
void CSender<TEvent>::send(const TEvent& event)
{ 
	for (auto it = _listenerList.begin(); it != _listenerList.end();) {
		auto& listener = it->get();

		if (!listener.isDestroyed()) {
			listener.onSended(event);
			++it;
		} else {
			it = _listenerList.erase(it);
		}
	}
}

}

#endif // _TINY_ENGINE_SENDER_HEADER_
