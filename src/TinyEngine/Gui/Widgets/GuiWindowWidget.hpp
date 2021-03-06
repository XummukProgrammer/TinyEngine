#ifndef _GUI_WINDOW_WIDGET_HEADER_
#define _GUI_WINDOW_WIDGET_HEADER_

#include <TinyEngine/Gui/GuiWidget.hpp>
#include <TinyEngine/Gui/GuiWidgetContainer.hpp>
#include <TinyEngine/Gui/Widgets/GuiMenuBarWidget.hpp>

#include <string>

namespace TinyEngine
{
	class GuiWindowWidget : public GuiWidget, public GuiWidgetContainer
	{
	public:
		using Ptr = std::shared_ptr<GuiWindowWidget>;

	public:
		GuiWindowWidget() = default;
		virtual ~GuiWindowWidget() = default;

	public:
		static Ptr Create(std::string_view name);

	public:
		void Draw(float deltaTime, IRenderWindowPtr renderWindowPtr) override;

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
		using Ptr = std::shared_ptr<GuiMainWindowWidget>;

	public:
		GuiMainWindowWidget() = default;
		~GuiMainWindowWidget() = default;

	public:
		static Ptr Create();

	public:
		void SetMenuBar(GuiMenuBarWidget::Ptr menuBarPtr);
		GuiMenuBarWidget::Ptr GetMenuBar() const { return _menuBarPtr; }

	protected:
		void BeginWindow() override;
		void EndWindow() override;

	private:
		GuiMenuBarWidget::Ptr _menuBarPtr;
	};
}

#endif // _GUI_WINDOW_WIDGET_HEADER_
