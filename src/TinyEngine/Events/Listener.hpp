#ifndef _TINY_ENGINE_LISTENER_HEADER_
#define _TINY_ENGINE_LISTENER_HEADER_

#include <functional>

namespace te
{

template<typename TEvent>
class CListener final
{
public:
	using SendedCallback = std::function<void(const TEvent&)>;

public:
	CListener(const SendedCallback& callback);
	~CListener() = default;

public:
	void onSended(const TEvent& event);

private:
	SendedCallback _onSendedCallback;
};

template<typename TEvent>
CListener<TEvent>::CListener(const SendedCallback& callback)
	: _onSendedCallback(callback)
{}

template<typename TEvent>
void CListener<TEvent>::onSended(const TEvent& event)
{ 
	if (_onSendedCallback) {
		_onSendedCallback(event);
	}
}

}

#endif // _TINY_ENGINE_LISTENER_HEADER_
