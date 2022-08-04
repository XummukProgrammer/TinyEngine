#ifndef _GUI_HEADER_
#define _GUI_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Data/Singleton.hpp>

#include <memory>

namespace TinyEngine
{
	class GuiDelegate
	{
	public:
		GuiDelegate() = default;
		virtual ~GuiDelegate() = default;

	public:
		virtual void Init(IRenderWindowSharedPtr renderWindowPtr) = 0;
		virtual void EventReceived(IRenderWindowSharedPtr renderWindowPtr) = 0;
		virtual void Update(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) = 0;
		virtual void Display(IRenderWindowSharedPtr renderWindowPtr) = 0;
		virtual void Shutdown(IRenderWindowSharedPtr renderWindowPtr) = 0;
	};

	class Gui final : public Singleton<Gui>
	{
	public:
		Gui() = default;
		~Gui() = default;

	public:
		void Init(IRenderWindowSharedPtr renderWindowPtr);
		void EventReceived(IRenderWindowSharedPtr renderWindowPtr);
		void Update(float deltaTime, IRenderWindowSharedPtr renderWindowPtr);
		void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr);
		void Display(IRenderWindowSharedPtr renderWindowPtr);
		void Shutdown(IRenderWindowSharedPtr renderWindowPtr);

	public:
		void SetDelegate(GuiDelegateUniquePtr&& delegatePtr) { _delegatePtr = std::move(delegatePtr); }

		void SetMainWindow(GuiMainWindowWidgetSharedPtr mainWindowPtr);
		GuiMainWindowWidgetSharedPtr GetMainWindow() const;

	private:
		void SettingsIO();

	private:
		GuiDelegateUniquePtr _delegatePtr;
		GuiMainWindowWidgetSharedPtr _mainWindowPtr;
	};
}

#endif // _GUI_HEADER_
