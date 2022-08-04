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
	class IMetaInfo
	{
	public:
		IMetaInfo() = default;
		virtual ~IMetaInfo() = default;

	public:
		virtual std::string GetName() const = 0;
		static std::string GetMetaName() { return ""; }
	};

	class Factory : public Singleton<Factory>
	{
	public:
		using CreateCallback = std::function<IMetaInfoSharedPtr()>;

	public:
		Factory() = default;
		~Factory() = default;

	public:
		template<typename T>
		void Register();

		template<typename T>
		std::shared_ptr<T> Create(std::string_view id) const;

		template<typename T>
		std::list<std::string> GetInheritorTypes() const;

	private:
		std::map<std::string, CreateCallback> _createCallbacks;
	};

	template<typename T>
	void Factory::Register()
	{
		_createCallbacks[T::GetMetaName()] = []()
		{
			return std::make_shared<T>();
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
}

#define TINY_ENGINE_META(cls) \
	public: \
		std::string GetName() const override { return #cls; } \
		static std::string GetMetaName() { return #cls; } \
	private:

#endif // _FACTORY_HEADER_
