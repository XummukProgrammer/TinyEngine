#ifndef _GUI_CONTROLLERS_HEADER_
#define _GUI_CONTROLLERS_HEADER_

#include "GuiController.hpp"

#include <memory>
#include <vector>

namespace TinyEngine
{
	class GuiControllers final
	{
	public:
		using GuiControllerPtr = std::unique_ptr<GuiController>;

	public:
		GuiControllers() = default;
		~GuiControllers() = default;

	public:
		void OnGuiRenderer();

	public:
		template<typename T>
		void AddController();

		template<typename T>
		T& GetController();

		template<typename T>
		const T& GetConstController() const;

		template<typename T>
		bool HasController() const;

	private:
		template<typename T>
		T* TryGetController() const;

	private:
		std::vector<GuiControllerPtr> _controllers;
	};
	
	template<typename T>
	void GuiControllers::AddController()
	{ 
		auto controller = std::make_unique<T>();
		_controllers.push_back(std::move(controller));
	}

	template<typename T>
	T& GuiControllers::GetController()
	{
		if (auto controller = TryGetController<T>())
		{
			return *controller;
		}

		static T controller;
		return controller;
	}

	template<typename T>
	inline const T& GuiControllers::GetConstController() const
	{
		if (const auto& controller = TryGetController<T>())
		{
			return *controller;
		}

		static const T controller;
		return controller;
	}

	template<typename T>
	bool GuiControllers::HasController() const
	{
		return TryGetController<T>() != nullptr;
	}

	template<typename T>
	T* GuiControllers::TryGetController() const
	{
		for (const auto& controller : _controllers)
		{
			if (auto castController = dynamic_cast<T*>(controller.get()))
			{
				return *castController;
			}
		}

		return nullptr;
	}
}

#endif // _GUI_CONTROLLERS_HEADER_
