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
	
	void setPosition(IPointIntRef pointRef) override;
	void getPosition(IPointIntRef pointRef) const override;

	void setSize(IPointUnsignedRef pointRef) override;
	void getSize(IPointUnsignedRef pointRef) const override;

	void setActive(bool isActive) override { _renderWindow.setActive(isActive); }
	void setVisible(bool isVisible) override { _renderWindow.setVisible(isVisible); }

	bool isOpen() const override { return _renderWindow.isOpen(); }

	void exec() override;
	void close() override { _renderWindow.close(); }

private:
	CRenderWindow _renderWindow;
	sf::Clock _clock;
	sf::Time _time;
};

}

#endif // _TINY_ENGINE_SFML_WINDOW_HEADER_
