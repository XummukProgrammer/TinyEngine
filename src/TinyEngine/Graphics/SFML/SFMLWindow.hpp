#ifndef _TINY_ENGINE_SFML_WINDOW_HEADER_
#define _TINY_ENGINE_SFML_WINDOW_HEADER_

#include <TinyEngine/Graphics/IWindow.hpp>

#include <SFML/Graphics.hpp>

#include <functional>
#include <memory>
#include <string>

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
	};

public:
	using CRenderWindowPtr = std::unique_ptr<sf::RenderWindow>;

public:
	CSFMLWindow(const CData& data);
	~CSFMLWindow() = default;

public:
	void create() override;
	void destroy() override;
	void exec() override;

private:
	CData _data;
	CRenderWindowPtr _renderWindowPtr;
};

}

#endif // _TINY_ENGINE_SFML_WINDOW_HEADER_
