#include "DebugWindowMessage.hpp"

#include <TinyEngine/Core/GUI/Widgets/Child/ChildImGUIView.hpp>

namespace TinyEngine
{
    void DebugWindowMessage::Init(const DebugLogMessage& message, bool isShowPrefix, bool isShowTime, bool isShowFunction)
    {
        _message = message;

        _prefix = MakeWidget<TextBox>("prefix");
        _sameLines.push_back(MakeWidget<SameLine>("sameline_1"));
        _time = MakeWidget<TextBox>("time");
        _sameLines.push_back(MakeWidget<SameLine>("sameline_2"));
        _function = MakeWidget<TextBox>("function");
        _sameLines.push_back(MakeWidget<SameLine>("sameline_3"));
        _text = MakeWidget<TextBox>("text");

        _prefix->SetText(String("[{}]").Params(message.GetPrefix()).Get());
        _prefix->SetColor(raylib::Color::Blue());

        _time->SetText(String("[{}]").Params(message.GetTime()).Get());
        _time->SetColor(raylib::Color::Green());

        _function->SetText(String("[{}]").Params(message.GetFunction()).Get());
        _function->SetColor(raylib::Color::Red());

        _text->SetText(message.GetText());

        _message = message;

        UpdateText(isShowPrefix, isShowTime, isShowFunction);

        dynamic_cast<ChildImGUIView*>(GetView())->SetSize({ 1000, 20 });
    }

    void DebugWindowMessage::UpdateText(bool isShowPrefix, bool isShowTime, bool isShowFunction)
    {
        _prefix->SetVisible(isShowPrefix);
        _time->SetVisible(isShowTime);
        _function->SetVisible(isShowFunction);

        _sameLines[0]->SetVisible(isShowPrefix);
        _sameLines[1]->SetVisible(isShowTime);
        _sameLines[2]->SetVisible(isShowFunction);
    }
}
