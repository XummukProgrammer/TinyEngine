#ifndef _TINY_ENGINE_LISTENER_HEADER_
#define _TINY_ENGINE_LISTENER_HEADER_

#include "Event.hpp"

#include <functional>
#include <memory>

namespace TE
{

template<typename TEvent>
class CListener final
{
public:
	static_assert(std::is_base_of_v<CEvent, TEvent>);

public:
	using CPtr = std::shared_ptr<CListener>;
	using SendedCallback = std::function<void(const TEvent&)>;

public:
	static CPtr create(const SendedCallback& callback);

public:
	CListener(const SendedCallback& callback);
	~CListener() = default;

	void onSended(const TEvent& event);

private:
	SendedCallback _onSendedCallback;
};

template<typename TEvent>
typename CListener<TEvent>::CPtr CListener<TEvent>::create(const SendedCallback& callback)
{
	return std::make_shared<CListener<TEvent>>(callback);
}

template<typename TEvent>
CListener<TEvent>::CListener(const SendedCallback& callback)
	: _onSendedCallback(callback)
{ 
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
