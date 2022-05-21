#ifndef _TINY_ENGINE_LISTENER_HEADER_
#define _TINY_ENGINE_LISTENER_HEADER_

#include "Event.hpp"

#include <functional>

namespace te
{

template<typename TEvent>
class CListener final
{
public:
	static_assert(std::is_base_of_v<CEvent, TEvent>);

public:
	using SendedCallback = std::function<void(const TEvent&)>;

public:
	CListener() = default;
	~CListener() = default;

public:
	void setOnSenderCallback(const SendedCallback& callback);

	void destroy();
	bool isDestroyed() const;

	void onSended(const TEvent& event);

private:
	SendedCallback _onSendedCallback;
};

template<typename TEvent>
void CListener<TEvent>::setOnSenderCallback(const SendedCallback& callback)
{ 
	_onSendedCallback = callback;
}

template<typename TEvent>
void CListener<TEvent>::destroy()
{ 
	_onSendedCallback = nullptr;
}

template<typename TEvent>
bool CListener<TEvent>::isDestroyed() const
{
	return _onSendedCallback == nullptr;
}

template<typename TEvent>
void CListener<TEvent>::onSended(const TEvent& event)
{ 
	if (_onSendedCallback) {
		_onSendedCallback(event);
	}
}

}

#endif // _TINY_ENGINE_LISTENER_HEADER_
