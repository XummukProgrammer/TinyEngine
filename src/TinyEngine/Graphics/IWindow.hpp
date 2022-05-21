#ifndef _TINY_ENGINE_INTERFACE_WINDOW_HEADER_
#define _TINY_ENGINE_INTERFACE_WINDOW_HEADER_

namespace te
{

class IWindow
{
public:
	IWindow() = default;
	virtual ~IWindow() = default;

public:
	virtual void create() = 0;
	virtual void destroy() = 0;
	virtual void exec() = 0;
};

}

#endif // _TINY_ENGINE_INTERFACE_WINDOW_HEADER_
