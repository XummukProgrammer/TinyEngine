#include "AssetHolder.hpp"

namespace TinyEngine
{
	void AssetHolder::OnLoad()
	{
		for (const auto& asset : _assets)
		{
			asset->OnLoad();
		}
	}
}
