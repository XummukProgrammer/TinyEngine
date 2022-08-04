#ifndef _SINGLETON_HEADER_
#define _SINGLETON_HEADER_

namespace TinyEngine
{
	template<typename T>
	class Singleton
	{
	public:
		Singleton() = default;
		virtual ~Singleton() = default;

	public:
		static T* GetInstance();
		void ResetInstance();

	private:
		static T* _instance;
	};

	template<typename T>
	T* Singleton<T>::_instance = nullptr;

	template<typename T>
	T* Singleton<T>::GetInstance()
	{
		if (!_instance)
		{
			_instance = new T();
		}

		return _instance;
	}

	template<typename T>
	void Singleton<T>::ResetInstance()
	{
		if (_instance)
		{
			delete _instance;
			_instance = nullptr;
		}
	}
}

#endif // _SINGLETON_HEADER_
