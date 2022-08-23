#ifndef _INTERFACE_RENDER_WINDOW_HEADER_
#define _INTERFACE_RENDER_WINDOW_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Render/IRenderObject.hpp>
#include <TinyEngine/Render/RenderWindowSettings.hpp>

#include <functional>

namespace TinyEngine
{
	class IRenderWindow
	{
	public:
		using EventReceivedCallback = std::function<void()>;

	public:
		IRenderWindow() = default;
		virtual ~IRenderWindow() = default;

	public:
		virtual void Create(const RenderWindowSettings& windowSettings) = 0;
		virtual GuiDelegateUniquePtr CreateDelegate() const = 0;
		virtual bool IsClosed() const = 0;
		virtual void Clear() = 0;
		virtual void ExtractEvents() = 0;
		virtual void Draw(IRenderObject* object) const = 0;
		virtual void Display() = 0;
		virtual void Close() = 0;

		virtual void ResetClock() = 0;
		virtual void UpdateClock() = 0;
		virtual float GetDeltaTime() const = 0;

	public:
		void SetOnEventReceived(const EventReceivedCallback& callback) { _onEventReceived = callback; }

	protected:
		void OnEventReceived() { if (_onEventReceived) _onEventReceived(); }

	private:
		EventReceivedCallback _onEventReceived;
	};
};

#endif // _INTERFACE_RENDER_WINDOW_HEADER_
