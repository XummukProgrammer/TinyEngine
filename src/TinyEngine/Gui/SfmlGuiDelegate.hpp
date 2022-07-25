#ifndef _SFML_GUI_DELEGATE_HEADER_
#define _SFML_GUI_DELEGATE_HEADER_

#include <TinyEngine/Gui/Gui.hpp>

namespace TinyEngine
{
	class SfmlGuiDelegate final : public GuiDelegate
	{
	public:
		SfmlGuiDelegate() = default;
		~SfmlGuiDelegate() = default;

	public:
		void Init(IRenderWindowPtr renderWindowPtr) override;
		void EventReceived(IRenderWindowPtr renderWindowPtr) override;
		void Update(float deltaTime, IRenderWindowPtr renderWindowPtr) override;
		void Display(IRenderWindowPtr renderWindowPtr) override;
		void Shutdown(IRenderWindowPtr renderWindowPtr) override;
	};
}

#endif // _SFML_GUI_DELEGATE_HEADER_
