#ifndef _TINY_ENGINE_INTERFACE_WINDOW_HEADER_
#define _TINY_ENGINE_INTERFACE_WINDOW_HEADER_

#include <TinyEngine/Events/Events.hpp>

#include <string>

namespace te
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

public:
	using CUpdateSender = CSender<CUpdateEvent>;

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

	virtual void destroy()
	{
		_updateSender.removeAllListeners();
	}

public:
	CUpdateSender& getUpdateSender() { return _updateSender; }

protected:
	void onUpdate(float deltaTime)
	{
		_updateSender.send(CUpdateEvent(deltaTime));
	}

private:
	CUpdateSender _updateSender;
};

}

#endif // _TINY_ENGINE_INTERFACE_WINDOW_HEADER_
