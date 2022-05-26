#ifndef _TINY_ENGINE_INTERFACE_WINDOW_HEADER_
#define _TINY_ENGINE_INTERFACE_WINDOW_HEADER_

#include <TinyEngine/Events/Events.hpp>
#include <TinyEngine/Graphics/IPoint.hpp>

#include <string>

namespace TE
{

class IWindow
{
public:
	class CUpdateEvent final : public CEvent
	{
	public:
		CUpdateEvent(float deltaTime)
			: _deltaTime(deltaTime)
		{}
		~CUpdateEvent() = default;

		float getDeltaTime() const { return _deltaTime; }

	private:
		float _deltaTime = 0.f;
	};

	class CDrawEvent final : public CEvent
	{
	public:
		CDrawEvent() = default;
		~CDrawEvent() = default;
	};

public:
	using CUpdateSender = CSender<CUpdateEvent>;
	using CDrawSender = CSender<CDrawEvent>;

public:
	IWindow() = default;
	virtual ~IWindow() = default;

public:
	virtual void setTitle(const std::string& title) = 0;

	virtual void setPosition(IPointInt* pointPtr) = 0;
	virtual void getPosition(IPointInt* pointPtr) const = 0;
	
	virtual void setSize(IPointUnsigned* pointPtr) = 0;
	virtual void getSize(IPointUnsigned* pointPtr) const = 0;

	virtual void setActive(bool isActive) = 0;
	virtual void setVisible(bool isVisible) = 0;

	virtual bool isOpen() const = 0;

	virtual void exec() = 0;
	virtual void close() = 0;

	virtual void destroy()
	{
		_updateSender.removeAllListeners();
		_drawSender.removeAllListeners();
	}

public:
	CUpdateSender& getUpdateSender() { return _updateSender; }
	CDrawSender& getDrawSender() { return _drawSender; }

protected:
	void onUpdate(float deltaTime)
	{
		_updateSender.send(CUpdateEvent(deltaTime));
	}

	void onDraw()
	{
		_drawSender.send(CDrawEvent());
	}

private:
	CUpdateSender _updateSender;
	CDrawSender _drawSender;
	
};

}

#endif // _TINY_ENGINE_INTERFACE_WINDOW_HEADER_
