#ifndef _QUEUE_HEADER_
#define _QUEUE_HEADER_

#include <vector>

namespace TinyEngine
{
	template<typename T>
	class Queue final
	{
	public:
		Queue() = default;
		~Queue() = default;

	public:
		void Push(const T& value);
		void Push(T&& value);
		const T& Front() const;
		void Pop();
		bool IsEmpty() const;
		
		const std::vector<T>& ToVector() const;

	private:
		std::vector<T> _queue;
	};

	template<typename T>
	void Queue<T>::Push(const T& value)
	{ 
		_queue.push_back(value);
	}

	template<typename T>
	void Queue<T>::Push(T&& value)
	{ 
		_queue.push_back(std::move(value));
	}

	template<typename T>
	const T& Queue<T>::Front() const
	{
		return _queue.front();
	}

	template<typename T>
	void Queue<T>::Pop()
	{
		if (IsEmpty())
		{
			return;
		}

		_queue.erase(_queue.begin());
	}

	template<typename T>
	bool Queue<T>::IsEmpty() const
	{
		return _queue.empty();
	}

	template<typename T>
	const std::vector<T>& Queue<T>::ToVector() const
	{
		return _queue;
	}
}

#endif // _QUEUE_HEADER_
