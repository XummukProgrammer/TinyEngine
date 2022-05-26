#ifndef _TINY_ENGINE_SENDER_HEADER_
#define _TINY_ENGINE_SENDER_HEADER_

#include "Listener.hpp"

#include <functional>
#include <list>
#include <memory>

namespace TE
{

template<typename TEvent>
class CSender final
{
public:
	static_assert(std::is_base_of_v<CEvent, TEvent>);

public:
	using CListenerBase = CListener<TEvent>;
	using CListenerWeakPtr = std::weak_ptr<CListenerBase>;
	using CListenerList = std::list<CListenerWeakPtr>;

public:
	CSender() = default;
	~CSender() = default;

public:
	void addListener(const CListenerWeakPtr& listenerWeakPtr);
	void clearListeners();

	void send(const TEvent& event);

private:
	CListenerList _listenerList;
};

template<typename TEvent>
void CSender<TEvent>::addListener(const CListenerWeakPtr& listenerWeakPtr)
{ 
	_listenerList.push_back(listenerWeakPtr);
}

template<typename TEvent>
void CSender<TEvent>::clearListeners()
{
	_listenerList.clear();
}

template<typename TEvent>
void CSender<TEvent>::send(const TEvent& event)
{ 
	for (auto it = _listenerList.begin(); it != _listenerList.end();) {
		if (auto sharedListenerPtr = it->lock()) {
			sharedListenerPtr->onSended(event);
			++it;
		} else {
			it = _listenerList.erase(it);
		}
	}
}

}

#endif // _TINY_ENGINE_SENDER_HEADER_
