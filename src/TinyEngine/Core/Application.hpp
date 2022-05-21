#ifndef _TINY_ENGINE_APPLICATION_HEADER_
#define _TINY_ENGINE_APPLICATION_HEADER_

#include <functional>

namespace te
{

class IWindow;

class CApplication final
{
public:
	using IWindowRef = std::reference_wrapper<IWindow>;

public:
	CApplication(IWindowRef windowRef);
	~CApplication() = default;

public:
	void exec();

private:
	IWindowRef _windowRef;
};

}

#endif // _TINY_ENGINE_APPLICATION_HEADER_
