#ifndef _DEBUG_WINDOW_HEADER_
#define _DEBUG_WINDOW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>
#include <TinyEngine/Core/GUI/Widgets/Button/Button.hpp>
#include <TinyEngine/Core/GUI/Widgets/SameLine/SameLine.hpp>
#include <TinyEngine/Editor/Debug/DebugWindowMessages.hpp>

#include <TinyEngine/Core/Debug/Debug.hpp>

#include <TinyEngine/Core/Events/Slot.hpp>

#include <vector>

namespace TinyEngine
{
	class DebugWindow : public Window
	{
	public:
		using ButtonPressedSlot = std::shared_ptr<Slot<>>;

	public:
		DebugWindow() = default;
		virtual ~DebugWindow() = default;

	public:
		virtual void OnInit() override;
		virtual void OnDeinit() override;

	private:
		void SetIsShowPrefix(bool isShow);
		void SetIsShowFunction(bool isShow);
		void SetIsShowTime(bool isShow);

		void TogglePrefixButtons();
		void ToggleFunctionButtons();
		void ToggleTimeButtons();

	private:
		void OnClear();

		void OnShowPrefix();
		void OnHidePrefix();

		void OnShowFunction();
		void OnHideFunction();

		void OnShowTime();
		void OnHideTime();

	private:
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
		DebugWindowMessages* _messages;
	};
}

#endif // _DEBUG_WINDOW_HEADER_
