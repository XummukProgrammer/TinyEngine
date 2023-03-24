#include "DebugWindow.hpp"

#include <TinyEngine/Core/Application/Application.hpp>

#include <TinyEngine/Core/Data/String.hpp>

namespace TinyEngine
{
    void DebugWindow::OnInit()
    {
        _clearButton = MakeWidget<Button>("ClearButton");
        _clearButton->SetText("Clear");
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

        _messages = MakeWidget<ImGUIDebugWindowMessages>("MessagesChild");
        _messages->SetTitle("MessagesChild");

        TogglePrefixButtons();
        ToggleFunctionButtons();
        ToggleTimeButtons();

        Window::OnInit();
    }

    void DebugWindow::OnDeinit()
    {
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

    void DebugWindow::SetIsShowPrefix(bool isShow)
    {
        _messages->SetIsShowPrefix(isShow);
        TogglePrefixButtons();
    }

    void DebugWindow::SetIsShowFunction(bool isShow)
    {
        _messages->SetIsShowFunction(isShow);
        ToggleFunctionButtons();
    }

    void DebugWindow::SetIsShowTime(bool isShow)
    {
        _messages->SetIsShowTime(isShow);
        ToggleTimeButtons();
    }

    void DebugWindow::TogglePrefixButtons()
    {
        _showPrefixButton->SetVisible(!_messages->IsShowPrefix());
        _hidePrefixButton->SetVisible(_messages->IsShowPrefix());
    }

    void DebugWindow::ToggleFunctionButtons()
    {
        _showFunctionButton->SetVisible(!_messages->IsShowFunction());
        _hideFunctionButton->SetVisible(_messages->IsShowFunction());
    }

    void DebugWindow::ToggleTimeButtons()
    {
        _showTimeButton->SetVisible(!_messages->IsShowTime());
        _hideTimeButton->SetVisible(_messages->IsShowTime());
    }

    void DebugWindow::OnClear()
    {
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
