#include "DebugWindowMessages.hpp"

#include <TinyEngine/Core/GUI/Widgets/Child/ChildImGUIView.hpp>

namespace TinyEngine
{
    void DebugWindowMessages::OnInit()
    {
        auto allLogMessages = Application::GetSingleton().GetRefContext().GetDebug()->GetDebugLogMessages(Debug::DebugLogMessagesType::All);
        for (const auto& message : allLogMessages->GetMessages())
        {
            AddMessage(message);
        }

        auto& onMessageAddedSignal = allLogMessages->GetOnMessageAddedSignal();
        _messageAddedSlot = onMessageAddedSignal.MakeSlot(std::bind(&DebugWindowMessages::OnMessageAdded, this, std::placeholders::_1));
        onMessageAddedSignal.Connect(_messageAddedSlot);

        dynamic_cast<ChildImGUIView*>(GetView())->SetIsHorizontalScrollbar(true);
    }

    void DebugWindowMessages::OnDeinit()
    {
        auto& onMessageAddedSignal = Application::GetSingleton().GetRefContext().GetDebug()->GetDebugLogMessages(Debug::DebugLogMessagesType::All)->GetOnMessageAddedSignal();
        onMessageAddedSignal.Disconnect(_messageAddedSlot);
        _messageAddedSlot.reset();
    }

    void DebugWindowMessages::AddMessage(const DebugLogMessage& message)
    {
        static int i = 0;
        auto msg = MakeWidget<DebugWindowMessage>(String("message_{}").Params(i).Get());
        msg->SetTitle(String("message_{}").Params(i).Get());
        msg->Init(message, &_showParams);
        ++i;

        _messages.push_back(msg);
    }

    void DebugWindowMessages::UpdateMessagesText()
    {
        for (const auto& msg : _messages)
        {
            msg->UpdateText();
        }
    }

    void DebugWindowMessages::SetIsShowPrefix(bool isShow)
    {
        _showParams.isShowPrefix = isShow;
        UpdateMessagesText();
    }

    void DebugWindowMessages::SetIsShowFunction(bool isShow)
    {
        _showParams.isShowFunction = isShow;
        UpdateMessagesText();
    }

    void DebugWindowMessages::SetIsShowTime(bool isShow)
    {
        _showParams.isShowTime = isShow;
        UpdateMessagesText();
    }

    void DebugWindowMessages::OnMessageAdded(const DebugLogMessage& message)
    {
        AddMessage(message);
    }
}
