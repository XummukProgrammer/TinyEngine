#ifndef _DEBUG_WINDOW_HEADER_
#define _DEBUG_WINDOW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Core/GUI/Widgets/TextBox/TextBox.hpp>
#include <TinyEngine/Core/GUI/Widgets/Button/Button.hpp>
#include <TinyEngine/Core/GUI/Widgets/SameLine/SameLine.hpp>
#include <TinyEngine/Core/GUI/Widgets/Child/Child.hpp>

#include <TinyEngine/Core/Debug/Debug.hpp>

#include <TinyEngine/Core/Events/Slot.hpp>

#include <vector>

namespace TinyEngine
{
	class DebugWindow : public Window
	{
	public:
		struct Msg
		{
			TextBox* prefix = nullptr;
			TextBox* time = nullptr;
			TextBox* function = nullptr;
			TextBox* text = nullptr;
			std::vector<SameLine*> sameLines;
			DebugLogMessage message;
		};

	public:
		using MessageAddedSlot = std::shared_ptr<Slot<const DebugLogMessage&>>;
		using ButtonPressedSlot = std::shared_ptr<Slot<>>;

	public:
		DebugWindow() = default;
		virtual ~DebugWindow() = default;

	public:
		virtual void OnInit() override;
		virtual void OnDeinit() override;

	private:
		void AddMessage(const DebugLogMessage& message);
		void UpdateMessagesText();
		void UpdateMessageText(const Msg& msg);

		void SetIsShowPrefix(bool isShow);
		void SetIsShowFunction(bool isShow);
		void SetIsShowTime(bool isShow);

		void TogglePrefixButtons();
		void ToggleFunctionButtons();
		void ToggleTimeButtons();

	private:
		void OnClear();

		void OnMessageAdded(const DebugLogMessage& message);

		void OnShowPrefix();
		void OnHidePrefix();

		void OnShowFunction();
		void OnHideFunction();

		void OnShowTime();
		void OnHideTime();

	private:
		MessageAddedSlot _messageAddedSlot;
		ButtonPressedSlot _clearSlot;
		ButtonPressedSlot _showPrefixSlot;
		ButtonPressedSlot _hidePrefixSlot;
		ButtonPressedSlot _showFunctionSlot;
		ButtonPressedSlot _hideFunctionSlot;
		ButtonPressedSlot _showTimeSlot;
		ButtonPressedSlot _hideTimeSlot;

	private:
		Button* _clearButton = nullptr;
		Button* _showPrefixButton = nullptr;
		Button* _showFunctionButton = nullptr;
		Button* _showTimeButton = nullptr;
		Button* _hidePrefixButton = nullptr;
		Button* _hideFunctionButton = nullptr;
		Button* _hideTimeButton = nullptr;
		Child* _messagesChild;

		std::vector<Msg> _msgs;

		bool _isShowPrefix = true;
		bool _isShowFunction = true;
		bool _isShowTime = true;
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
