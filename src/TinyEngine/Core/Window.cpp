#include "Window.hpp"

#include <TinyEngine/Core/Context.hpp>
#include <TinyEngine/Core/FileSystem.hpp>
#include <TinyEngine/Utils/XmlUtils.hpp>

#include <SFML/Graphics.hpp>
#include <pugixml.hpp>

namespace TinyEngine::Core
{
	static inline const std::string FILE_PATH = "window.xml";
	static inline const DirType DIR_TYPE = DirType::Configs;

	Window::Window()
		: Window(WindowInfo())
	{ }

	Window::Window(const WindowInfo& info)
	{ 
		_renderWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(info.width, info.height), info.title);
		_renderWindow->setFramerateLimit(info.maxFramerate);
		_renderWindow->setVerticalSyncEnabled(info.isVerticalSyncEnabled);
	}

	void Window::OnExecute()
	{ 
		while (_renderWindow->isOpen())
		{
			sf::Event event;
			while (_renderWindow->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					_renderWindow->close();
				}
				else
				{
					OnEvent();
				}
			}

			if (_renderWindow->hasFocus())
			{
				OnUpdate();
			}

			_renderWindow->clear();
			OnDraw();
			_renderWindow->display();
		}
	}

	void Window::Draw(const sf::Drawable& drawable)
	{ 
		_renderWindow->draw(drawable);
	}

	void Window::OnUpdate()
	{ 
		if (_onUpdateCallback)
		{
			_onUpdateCallback();
		}
	}

	void Window::OnDraw()
	{ 
		if (_onDrawCallback)
		{
			_onDrawCallback();
		}
	}

	void Window::OnEvent()
	{ 
		if (_onEventCallback)
		{
			_onEventCallback();
		}
	}

	void WindowInfo::LoadFromFile()
	{ 
		auto&& path = FileSystem::GetInstance().BuildPath(DIR_TYPE, FILE_PATH);

		pugi::xml_document doc;
		doc.load_file(path.c_str());
		auto root = doc.child("root");

		if (auto settingsNode = root.child("settings"))
		{
			width = Utils::XmlUtils::GetAttributeUnsignedOrDefault(settingsNode, "width", 800);
			height = Utils::XmlUtils::GetAttributeUnsignedOrDefault(settingsNode, "height", 600);
			title = Utils::XmlUtils::GetAttributeStringOrDefault(settingsNode, "title", "TinyEngine");
			maxFramerate = Utils::XmlUtils::GetAttributeUnsignedOrDefault(settingsNode, "maxFramerate", 60);
			isVerticalSyncEnabled = Utils::XmlUtils::GetAttributeBoolOrDefault(settingsNode, "isVerticalSyncEnabled", false);
		}
	}
}
