#ifndef _FACTORY_HEADER_
#define _FACTORY_HEADER_

#include <map>
#include <functional>
#include <memory>
#include <string>

namespace TinyEngine::Core
{
	class IFactory
	{
	public:
		IFactory() = default;
		virtual ~IFactory() = default;
	};

	class Factory final
	{
	public:
		using IFactoryPtr = std::shared_ptr<IFactory>;
		using CreateTypeCallback = std::function<IFactoryPtr()>;

	public:
		Factory() = default;
		~Factory() = default;

	public:
		template<typename T>
		void Register(std::string_view key);

		template<typename T>
		std::shared_ptr<T> Create(std::string_view key) const;

	private:
		std::map<std::string, CreateTypeCallback> _creator;
	};

	template<typename T>
	void Factory::Register(std::string_view key)
	{ 
		_creator.emplace(std::string{key}, []()
		{
			return std::make_shared<T>();
		});
	}

	template<typename T>
	std::shared_ptr<T> Factory::Create(std::string_view key) const
	{
		auto it = _creator.find(std::string{key});

		if (it != _creator.end())
		{
			if (it->second)
			{
				if (auto createdVar = it->second())
				{
					return std::dynamic_pointer_cast<T>(createdVar);
				}
			}
		}

		return nullptr;
	}
}

#endif // _FACTORY_HEADER_
