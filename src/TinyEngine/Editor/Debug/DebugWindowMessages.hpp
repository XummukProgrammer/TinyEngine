#ifndef _DEBUG_WINDOW_MESSAGES_HEADER_
#define _DEBUG_WINDOW_MESSAGES_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Child/Child.hpp>

#include <TinyEngine/Editor/Debug/DebugWindowMessage.hpp>

#include <TinyEngine/Core/Debug/Debug.hpp>

#include <TinyEngine/Core/Events/Slot.hpp>

namespace TinyEngine
{
	class DebugWindowMessages : public Child
	{
	public:
		using MessageAddedSlot = std::shared_ptr<Slot<const DebugLogMessage&>>;

	public:
		DebugWindowMessages() = default;
		virtual ~DebugWindowMessages() = default;

	public:
		virtual void OnInit() override;
		virtual void OnDeinit() override;

	public:
		void AddMessage(const DebugLogMessage& message);
		void UpdateMessagesText();

		void SetIsShowPrefix(bool isShow);
		void SetIsShowFunction(bool isShow);
		void SetIsShowTime(bool isShow);

		const DebugLogShowParams& GetShowParams() const { return _showParams; }

	private:
		void OnMessageAdded(const DebugLogMessage& message);

	private:
		MessageAddedSlot _messageAddedSlot;

	private:
		std::vector<DebugWindowMessage*> _messages;

		DebugLogShowParams _showParams;
	};
}

#endif // _DEBUG_WINDOW_MESSAGES_HEADER_
