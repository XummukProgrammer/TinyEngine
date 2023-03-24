#ifndef _DEBUG_WINDOW_HEADER_
#define _DEBUG_WINDOW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Core/GUI/Widgets/TextBox/TextBox.hpp>

#include <TinyEngine/Core/Debug/Debug.hpp>

#include <TinyEngine/Core/Events/Slot.hpp>

namespace TinyEngine
{
	class DebugWindow : public Window
	{
	public:
		using MessageAddedSlot = std::shared_ptr<Slot<const DebugLogMessage&>>;

	public:
		DebugWindow() = default;
		virtual ~DebugWindow() = default;

	public:
		virtual void OnInit() override;
		virtual void OnDeinit() override;

	private:
		void AddMessage(const DebugLogMessage& message);

	private:
		void OnMessageAdded(const DebugLogMessage& message);

	private:
		MessageAddedSlot _messageAddedSlot;
	};

	class DebugImGUIWindow final : public DebugWindow
	{
	public:
		DebugImGUIWindow() = default;
		~DebugImGUIWindow() = default;

	protected:
		virtual ViewType GetViewType() const override { return ViewType::ImGUI; }
	};
}

#endif // _DEBUG_WINDOW_HEADER_
