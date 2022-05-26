#ifndef _TINY_ENGINE_INTERFACE_POINT_HEADER_
#define _TINY_ENGINE_INTERFACE_POINT_HEADER_

#include <functional>

namespace TE
{

template<typename T>
class IPoint
{
public:
	IPoint() = default;
	virtual ~IPoint() = default;

public:
	virtual void setX(T value) = 0;
	virtual T getX() const = 0;

	virtual void setY(T value) = 0;
	virtual T getY() const = 0;

	void setPoint(T x, T y)
	{
		setX(x);
		setY(y);
	}
};

using IPointInt = IPoint<int>;
using IPointFloat = IPoint<float>;
using IPointUnsigned = IPoint<unsigned int>;

}

#endif // _TINY_ENGINE_INTERFACE_POINT_HEADER_
