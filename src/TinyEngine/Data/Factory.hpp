#ifndef _FACTORY_HEADER_
#define _FACTORY_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Data/Singleton.hpp>

#include <string>
#include <map>
#include <list>
#include <string>
#include <functional>
#include <memory>

namespace TinyEngine
{
	class Factory : public Singleton<Factory>
	{
	public:
		using CreateCallback = std::function<MetaClassSharedPtr()>;

	public:
		Factory() = default;
		~Factory() = default;

	public:
		template<typename T>
		void Register();

		template<typename T>
		std::shared_ptr<T> Create(std::string_view id) const;

		template<typename T>
		bool Has() const;

		template<typename T>
		std::list<std::string> GetInheritorTypes() const;

	private:
		std::map<std::string, CreateCallback> _createCallbacks;
	};

	template<typename T>
	void Factory::Register()
	{
		_createCallbacks[T::GetStaticClassName()] = []()
		{
			return T::CreateStaticSharedPtr();
		};
	}

	template<typename T>
	std::shared_ptr<T> Factory::Create(std::string_view id) const
	{
		auto it = _createCallbacks.find(std::string{id});
		if (it != _createCallbacks.end())
		{
			return std::dynamic_pointer_cast<T>(it->second());
		}

		return nullptr;
	}

	template<typename T>
	bool Factory::Has() const
	{
		auto it = _createCallbacks.find(std::string{id});
		return it != _createCallbacks.end();
	}

	template<typename T>
	std::list<std::string> Factory::GetInheritorTypes() const
	{
		std::list<std::string> types;

		for (const auto& [ id, callback ] : _createCallbacks)
		{
			if (auto object = callback())
			{
				if (std::dynamic_pointer_cast<T>(object))
				{
					types.push_back(id);
				}
			}
		}

		return types;
	}

	template<typename T>
	class FactoryAutoRegister
	{
	public:
		FactoryAutoRegister();
		virtual ~FactoryAutoRegister() = default;
	};

	template<typename T>
	FactoryAutoRegister<T>::FactoryAutoRegister()
	{
		Factory::GetInstance()->Register<T>();
	}
}

#define TINY_ENGINE_FACTORY_MEMBER(className) \
	private: \
		static FactoryAutoRegister<className> _autoRegisterStaticMember; \
	public:

#define TINY_ENGINE_FACTORY_MEMBER_IMPL(className) \
	TinyEngine::FactoryAutoRegister<className> className::_autoRegisterStaticMember;

#endif // _FACTORY_HEADER_
