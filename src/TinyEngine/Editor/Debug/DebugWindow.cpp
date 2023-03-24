#include "DebugWindow.hpp"

#include <TinyEngine/Core/Application/Application.hpp>

#include <TinyEngine/Core/Data/String.hpp>

#include <TinyEngine/Core/GUI/Widgets/SameLine/SameLine.hpp>

namespace TinyEngine
{
    void DebugWindow::OnInit()
    {
        _clearButton = MakeWidget<Button>("ClearButton");
        _clearButton->SetText("Clear Button");
        _clearSlot = _clearButton->GetOnPressedSignal().MakeSlot(std::bind(&DebugWindow::OnClear, this));
        _clearButton->GetOnPressedSignal().Connect(_clearSlot);

        MakeWidget<SameLine>("SameLine1");

        _showPrefixButton = MakeWidget<Button>("ShowPrefix");
        _showPrefixButton->SetText("Show Prefix");
        _showPrefixSlot = _showPrefixButton->GetOnPressedSignal().MakeSlot(std::bind(&DebugWindow::OnShowPrefix, this));
        _showPrefixButton->GetOnPressedSignal().Connect(_showPrefixSlot);

        _hidePrefixButton = MakeWidget<Button>("HidePrefix");
        _hidePrefixButton->SetText("Hide Prefix");
        _hidePrefixSlot = _hidePrefixButton->GetOnPressedSignal().MakeSlot(std::bind(&DebugWindow::OnHidePrefix, this));
        _hidePrefixButton->GetOnPressedSignal().Connect(_hidePrefixSlot);

        MakeWidget<SameLine>("SameLine1");

        _showFunctionButton = MakeWidget<Button>("ShowFunction");
        _showFunctionButton->SetText("Show Function");
        _showFunctionSlot = _showFunctionButton->GetOnPressedSignal().MakeSlot(std::bind(&DebugWindow::OnShowFunction, this));
        _showFunctionButton->GetOnPressedSignal().Connect(_showFunctionSlot);

        _hideFunctionButton = MakeWidget<Button>("HideFunction");
        _hideFunctionButton->SetText("Hide Function");
        _hideFunctionSlot = _hideFunctionButton->GetOnPressedSignal().MakeSlot(std::bind(&DebugWindow::OnHideFunction, this));
        _hideFunctionButton->GetOnPressedSignal().Connect(_hideFunctionSlot);

        MakeWidget<SameLine>("SameLine1");

        _showTimeButton = MakeWidget<Button>("ShowTime");
        _showTimeButton->SetText("Show Time");
        _showTimeSlot = _showTimeButton->GetOnPressedSignal().MakeSlot(std::bind(&DebugWindow::OnShowTime, this));
        _showTimeButton->GetOnPressedSignal().Connect(_showTimeSlot);

        _hideTimeButton = MakeWidget<Button>("HideTime");
        _hideTimeButton->SetText("Hide Time");
        _hideTimeSlot = _hideTimeButton->GetOnPressedSignal().MakeSlot(std::bind(&DebugWindow::OnHideTime, this));
        _hideTimeButton->GetOnPressedSignal().Connect(_hideTimeSlot);

        TogglePrefixButtons();
        ToggleFunctionButtons();
        ToggleTimeButtons();

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

        _clearButton->GetOnPressedSignal().Disconnect(_clearSlot);
        _clearSlot.reset();

        _showPrefixButton->GetOnPressedSignal().Disconnect(_showPrefixSlot);
        _showPrefixSlot.reset();

        _hidePrefixButton->GetOnPressedSignal().Disconnect(_hidePrefixSlot);
        _hidePrefixSlot.reset();

        _showFunctionButton->GetOnPressedSignal().Disconnect(_showFunctionSlot);
        _showFunctionSlot.reset();

        _hideFunctionButton->GetOnPressedSignal().Disconnect(_hideFunctionSlot);
        _hideFunctionSlot.reset();

        _showTimeButton->GetOnPressedSignal().Disconnect(_showTimeSlot);
        _showTimeSlot.reset();

        _hideTimeButton->GetOnPressedSignal().Disconnect(_hideTimeSlot);
        _hideTimeSlot.reset();

        Window::OnDeinit();
    }

    void DebugWindow::AddMessage(const DebugLogMessage& message)
    {
        auto msg = Msg();
        
        static int i = 0;
        msg.textBox = MakeWidget<TextBox>(String("message_{}").Params(i).Get());
        ++i;

        msg.textBox->SetText(message.GetString(_isShowPrefix, _isShowTime, _isShowFunction));

        msg.message = message;

        _msgs.push_back(msg);
    }

    void DebugWindow::UpdateMessagesText()
    {
        for (const auto& msg : _msgs)
        {
            msg.textBox->SetText(msg.message.GetString(_isShowPrefix, _isShowTime, _isShowFunction));
        }
    }

    void DebugWindow::SetIsShowPrefix(bool isShow)
    {
        _isShowPrefix = isShow;
        TogglePrefixButtons();
        UpdateMessagesText();
    }

    void DebugWindow::SetIsShowFunction(bool isShow)
    {
        _isShowFunction = isShow;
        ToggleFunctionButtons();
        UpdateMessagesText();
    }

    void DebugWindow::SetIsShowTime(bool isShow)
    {
        _isShowTime = isShow;
        ToggleTimeButtons();
        UpdateMessagesText();
    }

    void DebugWindow::TogglePrefixButtons()
    {
        _showPrefixButton->SetVisible(!_isShowPrefix);
        _hidePrefixButton->SetVisible(_isShowPrefix);
    }

    void DebugWindow::ToggleFunctionButtons()
    {
        _showFunctionButton->SetVisible(!_isShowFunction);
        _hideFunctionButton->SetVisible(_isShowFunction);
    }

    void DebugWindow::ToggleTimeButtons()
    {
        _showTimeButton->SetVisible(!_isShowTime);
        _hideTimeButton->SetVisible(_isShowTime);
    }

    void DebugWindow::OnClear()
    {
    }

    void DebugWindow::OnMessageAdded(const DebugLogMessage& message)
    {
        AddMessage(message);
    }

    void DebugWindow::OnShowPrefix()
    {
        SetIsShowPrefix(true);
    }

    void DebugWindow::OnHidePrefix()
    {
        SetIsShowPrefix(false);
    }

    void DebugWindow::OnShowFunction()
    {
        SetIsShowFunction(true);
    }

    void DebugWindow::OnHideFunction()
    {
        SetIsShowFunction(false);
    }

    void DebugWindow::OnShowTime()
    {
        SetIsShowTime(true);
    }

    void DebugWindow::OnHideTime()
    {
        SetIsShowTime(false);
    }
}
