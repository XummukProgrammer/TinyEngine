#ifndef _GUI_HEADER_
#define _GUI_HEADER_

#include <TinyEngine/Gui/GuiWidgetContainer.hpp>
#include <TinyEngine/Data/Singleton.hpp>

#include <memory>

namespace TinyEngine
{
	class GuiDelegate;

	using GuiDelegatePtr = std::shared_ptr<GuiDelegate>;

	class GuiDelegate
	{
	public:
		GuiDelegate() = default;
		virtual ~GuiDelegate() = default;

	public:
		virtual void Init(IRenderWindowPtr renderWindowPtr) = 0;
		virtual void EventReceived(IRenderWindowPtr renderWindowPtr) = 0;
		virtual void Update(float deltaTime, IRenderWindowPtr renderWindowPtr) = 0;
		virtual void Display(IRenderWindowPtr renderWindowPtr) = 0;
		virtual void Shutdown(IRenderWindowPtr renderWindowPtr) = 0;
	};

	class Gui final : public Singleton<Gui>
	{
	public:
		Gui() = default;
		~Gui() = default;

	public:
		void Init(IRenderWindowPtr renderWindowPtr);
		void EventReceived(IRenderWindowPtr renderWindowPtr);
		void Update(float deltaTime, IRenderWindowPtr renderWindowPtr);
		void Draw(float deltaTime, IRenderWindowPtr renderWindowPtr);
		void Display(IRenderWindowPtr renderWindowPtr);
		void Shutdown(IRenderWindowPtr renderWindowPtr);

	public:
		void SetDelegate(GuiDelegatePtr delegatePtr) { _delegatePtr = delegatePtr; }

		void SettingsIO();

	public:
		GuiWidgetContainer& GetContainer() { return _container; }
		const GuiWidgetContainer& GetConstContainer() { return _container; }

	private:
		GuiDelegatePtr _delegatePtr;
		GuiWidgetContainer _container;
	};
}

#endif // _GUI_HEADER_
