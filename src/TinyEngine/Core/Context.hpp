﻿#ifndef _CONTEXT_HEADER_
#define _CONTEXT_HEADER_

#include <TinyEngine/Utils/Singleton.hpp>

#include <functional>
#include <memory>

namespace TinyEngine::Properties
{
	class Properties;
	class XmlProperties;
}

namespace TinyEngine::Level
{
	class Level;
	class Scene;
	class Entity;
}

namespace TinyEngine::Render
{
	class Render;
}

namespace TinyEngine::Core
{
	class Context final : public std::enable_shared_from_this<Context>, public Utils::Singleton<Context>
	{
	public:
		using Ptr = std::shared_ptr<Context>;
		using PropertiesPtr = std::shared_ptr<Properties::Properties>;
		using XmlPropertiesPtr = std::shared_ptr<Properties::XmlProperties>;
		using LevelPtr = std::shared_ptr<Level::Level>;
		using ScenePtr = std::shared_ptr<Level::Scene>;
		using EntityPtr = std::shared_ptr<Level::Entity>;
		using RenderPtr = std::shared_ptr<Render::Render>;
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
		RenderPtr GetRender() const;

		// Методы для работы с сущностями используется только в сцене, как основном хранилище.
		// Не рекомендуется использовать методы на прямую.
		EntityPtr CreateEntity();
		void AddEntity(const EntityPtr& entity);
		void RemoveEntity(const EntityPtr& entity);
		void RemoveEntities();

		void AddScene(std::string_view key, const ScenePtr& scene);
		void SetCurrentScene(const ScenePtr& scene);
		ScenePtr GetCurrentScene() const;
		ScenePtr GetScene(std::string_view key) const;
		void RemoveScenes();

		XmlPropertiesPtr GetIOProperties() const;
		void IOPropertiesSaveToFile();
		void IOPropertiesLoadFromFile();

	private:
		PropertiesPtr _sessionProperties;
		XmlPropertiesPtr _IOProperties;
		LevelPtr _level;
		RenderPtr _render;

		PreInitCallback _onPreInitCallback;
		InitCallback _onInitCallback;
		DeinitCallback _onDeinitCallback;
		UpdateCallback _onUpdateCallback;
		DrawCallback _onDrawCallback;
		EventCallback _onEventCallback;
	};
}

#endif // _CONTEXT_HEADER_
