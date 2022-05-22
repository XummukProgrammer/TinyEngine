#ifndef _TINY_ENGINE_APPLICATION_HEADER_
#define _TINY_ENGINE_APPLICATION_HEADER_

#include <TinyEngine/Events/Events.hpp>
#include <TinyEngine/Graphics/Graphics.hpp>

#include <functional>

namespace TE
{

class CApplication final
{
public:
	using IWindowRef = std::reference_wrapper<IWindow>;
	using CWindowUpdateListener = CListener<IWindow::CUpdateEvent>;
	using CWindowDrawListener = CListener<IWindow::CDrawEvent>;

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
	void onDraw(const IWindow::CDrawEvent& drawEvent);

private:
	IWindowRef _windowRef;
	CWindowUpdateListener _windowUpdateListener;
	CWindowDrawListener _windowDrawListener;
};

}

#endif // _TINY_ENGINE_APPLICATION_HEADER_
