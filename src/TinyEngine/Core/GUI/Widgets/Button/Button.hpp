#ifndef _BUTTON_HEADER_
#define _BUTTON_HEADER_

#include <TinyEngine/Core/GUI/Widget.hpp>

#include <TinyEngine/Core/Events/Signal.hpp>

namespace TinyEngine
{
	class Button final : public Widget
	{
	public:
		using PressedSignal = Signal<>;

	public:
		Button() = default;
		~Button() = default;

	public:
		void OnPressed();
		PressedSignal& GetOnPressedSignal() { return _onPressedSignal; }

	public:
		void SetText(std::string_view text);

	protected:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;

	private:
		PressedSignal _onPressedSignal;
	};
}

#endif // _BUTTON_HEADER_
