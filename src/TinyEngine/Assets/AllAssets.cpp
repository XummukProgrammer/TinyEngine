#include "AllAssets.hpp"

namespace TinyEngine
{
	void AllAssets::OnAppEntry()
	{ 
		_textureAssets.OnAppEntry();
	}

	void AllAssets::OnAppQuit()
	{ 
		_textureAssets.OnAppQuit();
	}
}
