#include "LoaderManager.hpp"

#include <TinyEngine/Core/FileSystemManager.hpp>
#include <TinyEngine/Core/ILoader.hpp>

namespace TinyEngine::Core
{
	LoaderManager& LoaderManager::GetInstance()
	{
		static LoaderManager loaderManager;
		return loaderManager;
	}

	void LoaderManager::LoadFromFile(ILoader* loader)
	{ 
		auto&& filePath = FileSystemManager::GetInstance().BuildPath(loader->GetDirType(), loader->GetFilePath());

		loader->LoadFromFile(filePath);
	}
}
