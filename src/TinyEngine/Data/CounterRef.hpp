#ifndef _COUNTER_REF_HEADER_
#define _COUNTER_REF_HEADER_

namespace TinyEngine
{
	// Класс считает кол-во созданных объектов типа T.
	template<typename T, typename CounterType = unsigned>
	class CounterRef
	{
	public:
		CounterRef();
		virtual ~CounterRef() = default;

	public:
		// Получить глобальный счётчик объектов.
		static CounterType GetGeneralCounter();

	public:
		// Получить позицию в счётчике.
		CounterType GetThisCounter() const;

	protected:
		// Проинициализировать счётчик.
		void InitCounter();

	private:
		// Глобальный счётчик.
		static CounterType _generalCounter;

	private:
		// Позиция в счётчике.
		CounterType _thisCounter = 0;
	};

	template<typename T, typename CounterType>
	CounterType CounterRef<T, CounterType>::_generalCounter = 0;
	
	template<typename T, typename CounterType>
	CounterRef<T, CounterType>::CounterRef()
	{ 
		InitCounter();
	}

	template<typename T, typename CounterType>
	CounterType CounterRef<T, CounterType>::GetGeneralCounter()
	{
		return _generalCounter;
	}

	template<typename T, typename CounterType>
	CounterType CounterRef<T, CounterType>::GetThisCounter() const
	{
		return _thisCounter;
	}

	template<typename T, typename CounterType>
	inline void CounterRef<T, CounterType>::InitCounter()
	{ 
		_thisCounter = _generalCounter;
		++_generalCounter;
	}
}

#endif // _COUNTER_REF_HEADER_
