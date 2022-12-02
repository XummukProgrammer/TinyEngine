#ifndef _INTERFACE_RENDER_WINDOW_HEADER_
#define _INTERFACE_RENDER_WINDOW_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Singleton.hpp>
#include <TinyEngine/Core/Render/RenderObject.hpp>
#include <TinyEngine/Core/Render/RenderWindowSettings.hpp>

#include <functional>

namespace TinyEngine
{
	class RenderWindow final : public Singleton<RenderWindow>
	{
	public:
		using EventReceivedCallback = std::function<void()>;

	public:
		RenderWindow();
		~RenderWindow();

	public:
		void Create(const RenderWindowSettings& windowSettings);
		bool IsClosed() const;
		void Clear();
		void ExtractEvents();
		void Draw(RenderObject* object) const;
		void Display();
		void Close();

		void ResetClock();
		void UpdateClock();
		float GetDeltaTime() const;
	
		void SetOnEventReceived(const EventReceivedCallback& callback) { _onEventReceived = callback; }

	private:
		void OnEventReceived() { if (_onEventReceived) _onEventReceived(); }

	private:
		EventReceivedCallback _onEventReceived;
	};
};

#endif // _INTERFACE_RENDER_WINDOW_HEADER_
