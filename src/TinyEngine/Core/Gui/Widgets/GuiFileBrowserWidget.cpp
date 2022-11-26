#include "GuiFileBrowserWidget.hpp"

#include <TinyEngine/Core/Constants.hpp>

namespace TinyEngine
{
    GuiFileBrowserWidgetSharedPtr GuiFileBrowserWidget::Create()
    {
        auto widget = std::make_shared<GuiFileBrowserWidget>();
        return widget;
    }

    void GuiFileBrowserWidget::ShowOpenFile()
    {
        _state = FileBrowserState::OpenFile;
    }

    void GuiFileBrowserWidget::ShowSaveFile()
    {
        _state = FileBrowserState::SaveFile;
    }

    void GuiFileBrowserWidget::ShowSelectDirectory()
    {
        _state = FileBrowserState::SelectDirectory;
    }

    void GuiFileBrowserWidget::Hide()
    {
        _state = FileBrowserState::Hide;
    }

    void GuiFileBrowserWidget::Draw(float deltaTime)
    {
        if (_state == FileBrowserState::Hide)
        {
            return;
        }

        const std::string& stateId = magic_enum::enum_name(_state).data();

        ImGui::OpenPopup(stateId.c_str());
        
        if (_fileBrowser.showFileDialog(OPEN_FILE_ID, imgui_addons::ImGuiFileBrowser::DialogMode::OPEN, ImVec2(700, 310), _types))
        {
            GuiFileBrowserOpenFileEvent event;
            event.SetFileName(_fileBrowser.selected_fn);
            event.SetFilePath(_fileBrowser.selected_path);
            _onOpenFileSender.Send(&event);
            _state = FileBrowserState::Hide;
        }

        if (_fileBrowser.showFileDialog(SAVE_FILE_ID, imgui_addons::ImGuiFileBrowser::DialogMode::SAVE, ImVec2(700, 310), _types))
        {
            GuiFileBrowserSaveFileEvent event;
            event.SetFileName(_fileBrowser.selected_fn);
            event.SetFilePath(_fileBrowser.selected_path);
            event.SetFileExt(_fileBrowser.ext);
            _onSaveFileSender.Send(&event);
            _state = FileBrowserState::Hide;
        }

        if (_fileBrowser.showFileDialog(SELECT_DIRECTORY_ID, imgui_addons::ImGuiFileBrowser::DialogMode::SELECT, ImVec2(700, 310)))
        {
            GuiFileBrowserSelectDirectoryEvent event;
            event.SetDirectoryName(_fileBrowser.selected_fn);
            event.SetDirectoryPath(_fileBrowser.selected_path);
            _onSelectDirectorySender.Send(&event);
            _state = FileBrowserState::Hide;
        }
    }
}
