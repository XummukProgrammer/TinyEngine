#ifndef _TINY_ENGINE_SENDER_HEADER_
#define _TINY_ENGINE_SENDER_HEADER_

#include "Listener.hpp"

#include <functional>
#include <list>

namespace TE
{

template<typename TEvent>
class CSender final
{
public:
	static_assert(std::is_base_of_v<CEvent, TEvent>);

public:
	using CListenerBase = CListener<TEvent>;
	using CListenerRef = std::reference_wrapper<CListenerBase>;
	using CListenerList = std::list<CListenerRef>;

public:
	CSender() = default;
	~CSender() = default;

public:
	void addListener(const CListenerRef& listenerRef);
	void removeListener(const CListenerRef& listenerRef);
	void removeAllListeners();

	void send(const TEvent& event);

private:
	void clearRemoveListeners();

private:
	CListenerList _listenerList;
	bool _isDestroyProtectionActive = false;
};

template<typename TEvent>
void CSender<TEvent>::addListener(const CListenerRef& listenerRef)
{ 
	_listenerList.push_back(listenerRef);
}

template<typename TEvent>
void CSender<TEvent>::removeListener(const CListenerRef& listenerRef)
{ 
	listenerRef.get().destroy();

	clearRemoveListeners();
}

template<typename TEvent>
void CSender<TEvent>::removeAllListeners()
{ 
	for (auto& listenerRef : _listenerList) {
		listenerRef.get().destroy();
	}

	clearRemoveListeners();
}

template<typename TEvent>
void CSender<TEvent>::clearRemoveListeners()
{ 
	if (!_isDestroyProtectionActive) {
		_listenerList.remove_if([](const CListenerRef& ref) {
			return ref.get().isDestroyed();
		});
	}
}

template<typename TEvent>
void CSender<TEvent>::send(const TEvent& event)
{ 
	_isDestroyProtectionActive = true;

	for (auto it = _listenerList.begin(); it != _listenerList.end();) {
		auto& listener = it->get();

		if (!listener.isDestroyed()) {
			listener.onSended(event);
			++it;
		} else {
			it = _listenerList.erase(it);
		}
	}

	_isDestroyProtectionActive = false;
}

}

#endif // _TINY_ENGINE_SENDER_HEADER_
