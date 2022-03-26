#include "Render.hpp"

#include <algorithm>

namespace TinyEngine
{
	void Render::OnAppEntry()
	{
	}

	void Render::OnAppQuit()
	{
		RemoveLayouts();
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

	void Render::RemoveLayouts()
	{ 
		std::for_each(_layouts.begin(), _layouts.end(), [](ILayout* layout)
		{
			layout->RemoveObjects();
		});

		_layouts.clear();
	}

	size_t Render::GetObjectsCount() const
	{
		size_t count = 0;

		std::for_each(_layouts.begin(), _layouts.end(), [&count](ILayout* layout)
		{
			count += layout->GetObjectsCount();
		});

		return count;
	}
}
