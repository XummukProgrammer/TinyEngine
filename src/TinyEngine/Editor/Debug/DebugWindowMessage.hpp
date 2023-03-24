#ifndef _DEBUG_WINDOW_MESSAGE_HEADER_
#define _DEBUG_WINDOW_MESSAGE_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Child/Child.hpp>
#include <TinyEngine/Core/GUI/Widgets/TextBox/TextBox.hpp>
#include <TinyEngine/Core/GUI/Widgets/HorizontalLayout/HorizontalLayout.hpp>

#include <TinyEngine/Core/Debug/Debug.hpp>

namespace TinyEngine
{
	class DebugWindowMessage : public Child
	{
	public:
		DebugWindowMessage() = default;
		virtual ~DebugWindowMessage() = default;

	public:
		void Init(const DebugLogMessage& message, DebugLogShowParams* showParams);
		void UpdateText();

	private:
		HorizontalLayout* _horizontalLayout;
		TextBox* _prefix = nullptr;
		TextBox* _time = nullptr;
		TextBox* _function = nullptr;
		TextBox* _text = nullptr;
		
		DebugLogMessage _message;
		DebugLogShowParams* _showParams = nullptr;
	};
}

#endif // _DEBUG_WINDOW_MESSAGE_HEADER_
