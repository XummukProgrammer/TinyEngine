#include "DebugWindow.hpp"

#include <TinyEngine/Core/Application/Application.hpp>

#include <TinyEngine/Core/Data/String.hpp>

namespace TinyEngine
{
    void DebugWindow::OnInit()
    {
        auto allLogMessages = Application::GetSingleton().GetRefContext().GetDebug()->GetDebugLogMessages(Debug::DebugLogMessagesType::All);

        for (const auto& message : allLogMessages->GetMessages())
        {
            AddMessage(message);
        }

        auto& onMessageAddedSignal = allLogMessages->GetOnMessageAddedSignal();
        _messageAddedSlot = onMessageAddedSignal.MakeSlot(std::bind(&DebugWindow::OnMessageAdded, this, std::placeholders::_1));
        onMessageAddedSignal.Connect(_messageAddedSlot);

        Window::OnInit();
    }

    void DebugWindow::OnDeinit()
    {
        auto& onMessageAddedSignal = Application::GetSingleton().GetRefContext().GetDebug()->GetDebugLogMessages(Debug::DebugLogMessagesType::All)->GetOnMessageAddedSignal();
        onMessageAddedSignal.Disconnect(_messageAddedSlot);
        _messageAddedSlot.reset();

        Window::OnDeinit();
    }

    void DebugWindow::AddMessage(const DebugLogMessage& message)
    {
        static int i = 0;
        auto textBox = MakeWidget<TextBox>(String("message_{}").Params(i).Get());
        textBox->SetText(message.GetString());
        ++i;
    }

    void DebugWindow::OnMessageAdded(const DebugLogMessage& message)
    {
        AddMessage(message);
    }
}
