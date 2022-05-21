#ifndef _TINY_ENGINE_SENDER_HEADER_
#define _TINY_ENGINE_SENDER_HEADER_

#include "Listener.hpp"

#include <memory>
#include <list>

namespace te
{

template<typename TEvent>
class CSender final
{
public:
	using CListenerBase = CListener<TEvent>;
	using CListenerPtr = std::unique_ptr<CListenerBase>;
	using CListenerList = std::list<CListenerPtr>;

public:

public:
	CSender() = default;
	~CSender() = default;

public:
	void addListener(const typename CListenerBase::SendedCallback& callback);

	void send(const TEvent& event);

private:
	CListenerList _listenerList;
};

template<typename TEvent>
void CSender<TEvent>::addListener(const typename CListenerBase::SendedCallback& callback)
{ 
	auto listener = std::make_unique<CListenerBase>(callback);
	_listenerList.push_back(std::move(listener));
}

template<typename TEvent>
void CSender<TEvent>::send(const TEvent& event)
{ 
	for (const auto& listener : _listenerList) {
		listener->onSended(event);
	}
}

}

#endif // _TINY_ENGINE_SENDER_HEADER_
