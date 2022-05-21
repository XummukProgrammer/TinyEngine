#ifndef _TINY_ENGINE_INTERFACE_WINDOW_HEADER_
#define _TINY_ENGINE_INTERFACE_WINDOW_HEADER_

#include <string>

namespace te
{

class IWindow
{
public:
	IWindow() = default;
	virtual ~IWindow() = default;

public:
	virtual void setTitle(const std::string& title) = 0;
	virtual void setPosition(int x, int y) = 0;
	virtual void setSize(unsigned x, unsigned y) = 0;
	virtual void setActive(bool isActive) = 0;
	virtual void setVisible(bool isVisible) = 0;

	virtual bool isOpen() const = 0;

	virtual void exec() = 0;
	virtual void close() = 0;
};

}

#endif // _TINY_ENGINE_INTERFACE_WINDOW_HEADER_
