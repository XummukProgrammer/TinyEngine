#ifndef _FACTORY_HEADER_
#define _FACTORY_HEADER_

#include <TinyEngine/Data/Singleton.hpp>

#include <string>
#include <map>
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
		using IMetaInfoPtr = std::shared_ptr<IMetaInfo>;
		using CreateCallback = std::function<IMetaInfoPtr()>;

	public:
		Factory() = default;
		~Factory() = default;

	public:
		template<typename T>
		void Register();

		template<typename T>
		std::shared_ptr<T> Create(std::string_view id) const;

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
}

#define TINY_ENGINE_META(cls) \
	public: \
		std::string GetName() const override { return #cls; } \
		static std::string GetMetaName() { return #cls; } \
	private:

#define TINY_ENGINE_FACTORY_REGISTER(cls) \
	void FactoryRegisterFunction_##cls(); \
	struct FactoryRegisterClass_##cls \
	{ \
		FactoryRegisterClass_##cls() \
		{ \
			FactoryRegisterFunction_##cls(); \
		} \
	}; \
	FactoryRegisterClass_##cls _factoryRegisterClass_##cls; \
	void FactoryRegisterFunction_##cls() \
	{ \
		TinyEngine::Factory::GetInstance().Register<cls>(); \
	}

#endif // _FACTORY_HEADER_
