#ifndef _TINY_ENGINE_SFML_POINT_HEADER_
#define _TINY_ENGINE_SFML_POINT_HEADER_

#include <TinyEngine/Graphics/IPoint.hpp>

#include <SFML/System/Vector2.hpp>

namespace TE
{

template<typename T>
class SFMLPoint final : public IPoint<T>
{
public:
	SFMLPoint(T x, T y)
		: _point(x, y)
	{}
	~SFMLPoint() = default;

public:
	void setX(T value) override;
	T getX() const override;

	void setY(T value) override;
	T getY() const override;

private:
	sf::Vector2<T> _point;
};

template<typename T>
void SFMLPoint<T>::setX(T value)
{ 
	_point.x = value;
}

template<typename T>
T SFMLPoint<T>::getX() const
{
	return _point.x;
}

template<typename T>
void SFMLPoint<T>::setY(T value)
{ 
	_point.y = value;
}

template<typename T>
T SFMLPoint<T>::getY() const
{
	return _point.y;
}

}

#endif // _TINY_ENGINE_SFML_POINT_HEADER_
