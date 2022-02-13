#ifndef _LOADER_MANAGER_HEADER_
#define _LOADER_MANAGER_HEADER_

namespace TinyEngine::Core
{
	class ILoader;

	class LoaderManager final
	{
	public:
		LoaderManager() = default;
		~LoaderManager() = default;

	public:
		static LoaderManager& GetInstance();

	public:
		void LoadFromFile(ILoader* loader);
	};
}

#endif // _LOADER_MANAGER_HEADER_
