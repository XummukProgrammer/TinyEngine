#include "Render.hpp"

#include <algorithm>

namespace TinyEngine
{
	void Render::OnAppEntry()
	{
	}

	void Render::OnAppQuit()
	{
	}

	void Render::OnWindowUpdated()
	{ 
		std::for_each(_layouts.begin(), _layouts.end(), [](ILayout* layout)
		{
			layout->OnWindowUpdated();
		});
	}

	void Render::OnWindowDrawed()
	{ 
		std::for_each(_layouts.begin(), _layouts.end(), [](ILayout* layout)
		{
			layout->OnWindowDrawed();
		});
	}

	void Render::AddLayout(ILayout* layout)
	{
		_layouts.push_back(layout);
	}

	void Render::RemoveLayout(const ILayout* layout)
	{ 
		auto it = std::find(_layouts.begin(), _layouts.end(), layout);

		if (it != _layouts.end())
		{
			_layouts.erase(it);
		}
	}
}
