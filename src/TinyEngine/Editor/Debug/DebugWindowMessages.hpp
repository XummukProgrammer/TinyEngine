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
		bool IsShowPrefix() const { return _isShowPrefix; }

		void SetIsShowFunction(bool isShow);
		bool IsShowFunction() const { return _isShowFunction; }

		void SetIsShowTime(bool isShow);
		bool IsShowTime() const { return _isShowTime; }

	private:
		void OnMessageAdded(const DebugLogMessage& message);

	private:
		MessageAddedSlot _messageAddedSlot;

	private:
		std::vector<ImGUIDebugWindowMessage*> _messages;

		bool _isShowPrefix = true;
		bool _isShowFunction = true;
		bool _isShowTime = true;
	};

	class ImGUIDebugWindowMessages final : public DebugWindowMessages
	{
	public:
		ImGUIDebugWindowMessages() = default;
		~ImGUIDebugWindowMessages() = default;

	protected:
		virtual ViewType GetViewType() const override { return ViewType::ImGUI; }
	};
}

#endif // _DEBUG_WINDOW_MESSAGES_HEADER_
