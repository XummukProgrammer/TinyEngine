#ifndef _GUI_WINDOW_WIDGET_HEADER_
#define _GUI_WINDOW_WIDGET_HEADER_

#include <TinyEngine/Core/Gui/GuiWidget.hpp>
#include <TinyEngine/Core/Gui/GuiWidgetContainer.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiMenuBarWidget.hpp>

#include <string>

namespace TinyEngine
{
	class GuiWindowWidget : public GuiWidget, public GuiWidgetContainer
	{
	public:
		GuiWindowWidget() = default;
		virtual ~GuiWindowWidget() = default;

	public:
		static GuiWindowWidgetSharedPtr Create(std::string_view name);

	public:
		void Draw(float deltaTime) override;

	public:
		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

	protected:
		virtual void BeginWindow();
		virtual void EndWindow();

	private:
		std::string _name;
	};

	class GuiMainWindowWidget final : public GuiWindowWidget
	{
	public:
		GuiMainWindowWidget() = default;
		~GuiMainWindowWidget() = default;

	public:
		static GuiMainWindowWidgetSharedPtr Create();

	public:
		void SetMenuBar(GuiMenuBarWidgetSharedPtr menuBarPtr);
		GuiMenuBarWidgetSharedPtr GetMenuBar() const { return _menuBarPtr; }

	protected:
		void BeginWindow() override;
		void EndWindow() override;

	private:
		GuiMenuBarWidgetSharedPtr _menuBarPtr;
	};
}

#endif // _GUI_WINDOW_WIDGET_HEADER_
