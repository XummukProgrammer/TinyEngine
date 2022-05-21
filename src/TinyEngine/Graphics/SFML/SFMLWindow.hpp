#ifndef _TINY_ENGINE_SFML_WINDOW_HEADER_
#define _TINY_ENGINE_SFML_WINDOW_HEADER_

#include <TinyEngine/Graphics/IWindow.hpp>

#include <SFML/Graphics.hpp>

#include <functional>

namespace te
{

class CSFMLWindow final : public IWindow
{
public:
	struct CData
	{
		unsigned width;
		unsigned height;
		std::string title;
		unsigned maxFramerate;
	};

public:
	using CRenderWindow = sf::RenderWindow;

public:
	CSFMLWindow(const CData& data);
	~CSFMLWindow() = default;

public:
	void setTitle(const std::string& title) override { _renderWindow.setTitle(title); }
	void setPosition(int x, int y) override { _renderWindow.setPosition({ x, y }); }
	void setSize(unsigned x, unsigned y) override { _renderWindow.setSize({ x, y }); }
	void setActive(bool isActive) override { _renderWindow.setActive(isActive); }
	void setVisible(bool isVisible) override { _renderWindow.setVisible(isVisible); }

	bool isOpen() const override { return _renderWindow.isOpen(); }

	void exec() override;
	void close() override { _renderWindow.close(); }

private:
	CRenderWindow _renderWindow;
};

}

#endif // _TINY_ENGINE_SFML_WINDOW_HEADER_
