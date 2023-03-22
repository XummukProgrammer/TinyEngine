#ifndef _POPUP_HEADER_
#define _POPUP_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>

namespace TinyEngine
{
	class Popup : public Window
	{
	public:
		Popup() = default;
		virtual ~Popup() = default;

	public:
		void Open();

	protected:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;
	};

	class ImGUIPopup final : public Popup
	{
	public:
		ImGUIPopup() = default;
		~ImGUIPopup() = default;

	protected:
		virtual ViewType GetViewType() const override { return ViewType::ImGUI; }
	};
}

#endif // _POPUP_HEADER_
