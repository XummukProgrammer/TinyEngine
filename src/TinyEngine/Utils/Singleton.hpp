#ifndef _SINGLETON_HEADER_
#define _SINGLETON_HEADER_

#include <memory>

namespace TinyEngine::Utils
{
	template<typename T>
	class Singleton
	{
	public:
		Singleton() = default;
		virtual ~Singleton() = default;

	public:
		static T& GetInstance();

	private:
		static std::unique_ptr<T> _instance;
	};

	template<typename T>
	std::unique_ptr<T> Singleton<T>::_instance;

	template<typename T>
	T& Singleton<T>::GetInstance()
	{
		if (!_instance)
		{
			_instance = std::make_unique<T>();
		}

		return *_instance.get();
	}
}

#endif // _SINGLETON_HEADER_
