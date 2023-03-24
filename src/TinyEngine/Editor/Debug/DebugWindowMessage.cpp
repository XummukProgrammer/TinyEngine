#include "DebugWindowMessage.hpp"

#include <TinyEngine/Core/GUI/Widgets/Child/ChildImGUIView.hpp>

namespace TinyEngine
{
    void DebugWindowMessage::Init(const DebugLogMessage& message, DebugLogShowParams* showParams)
    {
        _message = message;
        _showParams = showParams;

        _horizontalLayout = MakeWidget<HorizontalLayout>("HorizontalLayout");

        _prefix = _horizontalLayout->MakeWidget<TextBox>("prefix");
        _time = _horizontalLayout->MakeWidget<TextBox>("time");
        _function = _horizontalLayout->MakeWidget<TextBox>("function");
        _text = _horizontalLayout->MakeWidget<TextBox>("text");

        _prefix->SetText(String("[{}]").Params(message.GetPrefix()).Get());
        _prefix->SetColor(raylib::Color::Blue());

        _time->SetText(String("[{}]").Params(message.GetTime()).Get());
        _time->SetColor(raylib::Color::Green());

        _function->SetText(String("[{}]").Params(message.GetFunction()).Get());
        _function->SetColor(raylib::Color::Red());

        _text->SetText(message.GetText());

        _message = message;

        UpdateText();

        dynamic_cast<ChildImGUIView*>(GetView())->SetSize({ 1000, 20 });
    }

    void DebugWindowMessage::UpdateText()
    {
        _prefix->SetVisible(_showParams->isShowPrefix);
        _time->SetVisible(_showParams->isShowTime);
        _function->SetVisible(_showParams->isShowFunction);
    }
}
