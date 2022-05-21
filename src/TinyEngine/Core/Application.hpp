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
	struct CContext
	{
		IWindowRef windowRef;

		CContext(IWindowRef windowRef)
			: windowRef(windowRef)
		{}
	};

public:
	CApplication(IWindowRef windowRef)
		: _context(windowRef)
	{}
	~CApplication() = default;

public:
	void exec();

private:
	void init();
	void deinit();

private:
	CContext _context;
};

}

#endif // _TINY_ENGINE_APPLICATION_HEADER_
