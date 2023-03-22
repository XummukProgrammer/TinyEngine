#ifndef _WIDGETS_LAYERS_CONTAINER_HEADER_
#define _WIDGETS_LAYERS_CONTAINER_HEADER_

#include <TinyEngine/Core/GUI/Widget.hpp>

#include <vector>
#include <memory>
#include <string>
#include <map>

namespace TinyEngine
{
	class WidgetsLayerContainer final
	{
	public:
		WidgetsLayerContainer() = default;
		~WidgetsLayerContainer() = default;

	public:
		void Init();
		void Deinit();
		void Draw();

	public:
		template<typename T>
		T* MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback);
		bool HasWidget(std::string_view name) const;
		template<typename T>
		T* GetWidget(std::string_view name) const;
		template<typename T>
		T* GetBackWidget() const;

	private:
		std::vector<std::unique_ptr<Widget>> _widgets;
	};

	template<typename T>
	T* WidgetsLayerContainer::MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		auto widget = std::make_unique<T>();

		widget->SetName(widgetName);
		widget->MakeView(widgetType, makeCallback);

		_widgets.push_back(std::move(widget));
		auto backWidget = GetBackWidget<T>();
		backWidget->OnInit();
		return backWidget;
	}

	template<typename T>
	T* WidgetsLayerContainer::GetWidget(std::string_view name) const
	{
		auto it = std::find_if(_widgets.begin(), _widgets.end(), [name](const std::unique_ptr<Widget>& widget)
			{
				return widget->GetName() == name;
			});

		if (it != _widgets.end())
		{
			return static_cast<T*>(it->get());
		}

		return nullptr;
	}

	template<typename T>
	T* WidgetsLayerContainer::GetBackWidget() const
	{
		return static_cast<T*>(_widgets.back().get());
	}
}

#endif // _WIDGETS_LAYERS_CONTAINER_HEADER_
