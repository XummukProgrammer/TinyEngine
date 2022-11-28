#ifndef _GUI_FILE_BROWSER_WIDGET_HEADER_
#define _GUI_FILE_BROWSER_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Constants.hpp>
#include <TinyEngine/Core/Gui/GuiWidget.hpp>

#include <TinyEngine/Core/Event/EventSender.hpp>
#include <TinyEngine/Core/Event/Event.hpp>

#include <TinyEngine/Libs/ImGui-Addons/FileBrowser/ImGuiFileBrowser.h>

#include <magic_enum.hpp>

#include <string>

namespace TinyEngine
{
	class GuiFileBrowserBaseEvent : public Event
	{
	public:
		GuiFileBrowserBaseEvent() = default;
		virtual ~GuiFileBrowserBaseEvent() = default;

	public:
		void SetFileName(std::string_view fileName) { _fileName = fileName; }
		const std::string& GetFileName() const { return _fileName; }

		void SetFilePath(std::string_view filePath) { _filePath = filePath; }
		const std::string& GetFilePath() const { return _filePath; }

		void SetSource(std::string_view source) { _source = source; }
		const std::string& GetSource() const { return _source; }

	private:
		std::string _fileName;
		std::string _filePath;
		std::string _source;
	};

	class GuiFileBrowserOpenFileEvent final : public GuiFileBrowserBaseEvent
	{
	public:
		GuiFileBrowserOpenFileEvent() = default;
		~GuiFileBrowserOpenFileEvent() = default;
	};

	class GuiFileBrowserSaveFileEvent final : public GuiFileBrowserBaseEvent
	{
	public:
		GuiFileBrowserSaveFileEvent() = default;
		~GuiFileBrowserSaveFileEvent() = default;

	public:
		void SetFileExt(std::string_view fileExt) { _fileExt = fileExt; }
		const std::string& GetFileExt() const { return _fileExt; }

	private:
		std::string _fileExt;
	};

	class GuiFileBrowserSelectDirectoryEvent final : public Event
	{
	public:
		GuiFileBrowserSelectDirectoryEvent() = default;
		~GuiFileBrowserSelectDirectoryEvent() = default;

	public:
		void SetDirectoryName(std::string_view directoryName) { _directoryName = directoryName; }
		const std::string& GetDirectoryName() const { return _directoryName; }

		void SetDirectoryPath(std::string_view directoryPath) { _directoryPath = directoryPath; }
		const std::string& GetDirectoryPath() const { return _directoryPath; }

		void SetSource(std::string_view source) { _source = source; }
		const std::string& GetSource() const { return _source; }

	private:
		std::string _directoryName;
		std::string _directoryPath;
		std::string _source;
	};

	class GuiFileBrowserWidget final : public GuiWidget
	{
	public:
		
	public:
		GuiFileBrowserWidget() = default;
		~GuiFileBrowserWidget() = default;

	public:
		static GuiFileBrowserWidgetSharedPtr Create();

	public:
		void ShowOpenFile();
		void ShowSaveFile();
		void ShowSelectDirectory();
		void Hide();

		void SetTypes(std::string_view types) { _types = types; }

		void SetSource(std::string_view source) { _source = source; }

		EventSender& GetOnOpenFileSender() { return _onOpenFileSender; }
		EventSender& GetOnSaveFileSender() { return _onSaveFileSender; }
		EventSender& GetOnSelectDirectorySender() { return _onSelectDirectorySender; }

	public:
		void Draw(float deltaTime) override;

	private:
		void Reset();

		void OnShowOpenFileDialog();
		void OnShowSaveFileDialog();
		void OnShowSelectDirectoryDialog();

	private:
		imgui_addons::ImGuiFileBrowser _fileBrowser;
		FileBrowserState _state = FileBrowserState::Hide;
		std::string _types;

		std::string _source;

		EventSender _onOpenFileSender;
		EventSender _onSaveFileSender;
		EventSender _onSelectDirectorySender;

	private:
		static inline const std::string OPEN_FILE_ID = magic_enum::enum_name(FileBrowserState::OpenFile).data();
		static inline const std::string SAVE_FILE_ID = magic_enum::enum_name(FileBrowserState::SaveFile).data();
		static inline const std::string SELECT_DIRECTORY_ID = magic_enum::enum_name(FileBrowserState::SelectDirectory).data();
	};
}

#endif // _GUI_FILE_BROWSER_WIDGET_HEADER_
