#ifndef _TINY_ENGINE_APPLICATION_HEADER_
#define _TINY_ENGINE_APPLICATION_HEADER_

#include <TinyEngine/Events/Events.hpp>
#include <TinyEngine/Graphics/Graphics.hpp>

#include <functional>

namespace te
{

class CApplication final
{
public:
	using IWindowRef = std::reference_wrapper<IWindow>;
	using CWindowUpdateListener = CListener<IWindow::CUpdateEvent>;

public:
	CApplication(IWindowRef windowRef);
	~CApplication() = default;

public:
	void exec();

private:
	void init();
	void destroy();

private:
	void onUpdate(const IWindow::CUpdateEvent& updateEvent);

private:
	IWindowRef _windowRef;
	CWindowUpdateListener _windowUpdateListener;
};

}

#endif // _TINY_ENGINE_APPLICATION_HEADER_
