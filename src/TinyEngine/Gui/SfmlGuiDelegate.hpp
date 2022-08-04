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
		void Init(IRenderWindowSharedPtr renderWindowPtr) override;
		void EventReceived(IRenderWindowSharedPtr renderWindowPtr) override;
		void Update(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) override;
		void Display(IRenderWindowSharedPtr renderWindowPtr) override;
		void Shutdown(IRenderWindowSharedPtr renderWindowPtr) override;
	};
}

#endif // _SFML_GUI_DELEGATE_HEADER_
