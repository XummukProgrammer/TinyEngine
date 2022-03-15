#ifndef _CONTEXT_HEADER_
#define _CONTEXT_HEADER_

#include <TinyEngine/Utils/Singleton.hpp>

#include <functional>
#include <memory>

namespace TinyEngine::Properties
{
	class PropertiesData;
	class XmlPropertiesData;
}

namespace TinyEngine::Core
{
	class Context final : public Utils::Singleton<Context>
	{
	public:
		using Ptr = std::shared_ptr<Context>;
		using PropertiesDataPtr = std::shared_ptr<Properties::PropertiesData>;
		using XmlPropertiesDataPtr = std::shared_ptr<Properties::XmlPropertiesData>;
		using PreInitCallback = std::function<void()>;
		using InitCallback = std::function<void()>;
		using DeinitCallback = std::function<void()>;
		using UpdateCallback = std::function<void()>;
		using DrawCallback = std::function<void()>;
		using EventCallback = std::function<void()>;

	public:
		Context();
		~Context() = default;

	public:
		void SetOnPreInitCallback(const PreInitCallback& callback) { _onPreInitCallback = callback; }
		void OnPreInit();

		void SetOnInitCallback(const InitCallback& callback) { _onInitCallback = callback; }
		void OnInit();

		void SetOnDeinitCallback(const DeinitCallback& callback) { _onDeinitCallback = callback; }
		void OnDeinit();

		void SetOnUpdateCallback(const UpdateCallback& callback) { _onUpdateCallback = callback; }
		void OnUpdate();

		void SetOnDrawCallback(const DrawCallback& callback) { _onDrawCallback = callback; }
		void OnDraw();

		void SetOnEventCallback(const EventCallback& callback) { _onEventCallback = callback; }
		void OnEvent();

	public:
		PropertiesDataPtr GetSessionProperties() const;
		
		XmlPropertiesDataPtr GetIOProperties() const;
		std::string GetIOPropertiesPath() const;

	private:
		PropertiesDataPtr _sessionProperties;
		XmlPropertiesDataPtr _IOProperties;

		PreInitCallback _onPreInitCallback;
		InitCallback _onInitCallback;
		DeinitCallback _onDeinitCallback;
		UpdateCallback _onUpdateCallback;
		DrawCallback _onDrawCallback;
		EventCallback _onEventCallback;
	};
}

#endif // _CONTEXT_HEADER_
