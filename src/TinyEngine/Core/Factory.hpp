#ifndef _FACTORY_HEADER_
#define _FACTORY_HEADER_

#include <TinyEngine/Utils/Singleton.hpp>

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

	public:
		virtual std::string GetClassName() const = 0;
		static std::string GetStaticClassName() { return "IFactory"; }
	};

	class Factory final : public Utils::Singleton<Factory>
	{
	public:
		using IFactoryPtr = std::shared_ptr<IFactory>;
		using CreateTypeCallback = std::function<IFactoryPtr()>;

	public:
		Factory() = default;
		~Factory() = default;

	public:
		template<typename T>
		void Register();

		template<typename T>
		std::shared_ptr<T> Create(std::string_view key) const;

	private:
		std::map<std::string, CreateTypeCallback> _creator;
	};

	template<typename T>
	void Factory::Register()
	{ 
		_creator.emplace(T::GetStaticClassName(), []()
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

#define FACTORY_CLASS(className) \
	public: \
		static std::string GetStaticClassName() { return #className; } \
		virtual std::string GetClassName() const { return className::GetStaticClassName(); } \
	private:

#endif // _FACTORY_HEADER_
