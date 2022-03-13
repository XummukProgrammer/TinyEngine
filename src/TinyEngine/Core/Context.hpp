#ifndef _CONTEXT_HEADER_
#define _CONTEXT_HEADER_

#include <TinyEngine/Utils/Singleton.hpp>

#include <functional>
#include <memory>

namespace TinyEngine::Properties
{
	class Properties;
	class XmlProperties;
}

namespace TinyEngine::Core
{
	class Context final : public std::enable_shared_from_this<Context>, public Utils::Singleton<Context>
	{
	public:
		using Ptr = std::shared_ptr<Context>;
		using PropertiesPtr = std::shared_ptr<Properties::Properties>;
		using XmlPropertiesPtr = std::shared_ptr<Properties::XmlProperties>;
		using PreInitCallback = std::function<void(const Ptr&)>;
		using InitCallback = std::function<void(const Ptr&)>;
		using DeinitCallback = std::function<void(const Ptr&)>;
		using UpdateCallback = std::function<void(const Ptr&)>;
		using DrawCallback = std::function<void(const Ptr&)>;
		using EventCallback = std::function<void(const Ptr&)>;

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
		PropertiesPtr GetSessionProperties() const;

		XmlPropertiesPtr GetIOProperties() const;
		void IOPropertiesSaveToFile();
		void IOPropertiesLoadFromFile();

	private:
		PropertiesPtr _sessionProperties;
		XmlPropertiesPtr _IOProperties;

		PreInitCallback _onPreInitCallback;
		InitCallback _onInitCallback;
		DeinitCallback _onDeinitCallback;
		UpdateCallback _onUpdateCallback;
		DrawCallback _onDrawCallback;
		EventCallback _onEventCallback;
	};
}

#endif // _CONTEXT_HEADER_
