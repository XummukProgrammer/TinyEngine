#ifndef _POINT_HEADER_
#define _POINT_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

namespace TinyEngine
{
	class Point : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Point)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_x, "X", "X");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_y, "Y", "Y");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Point(int x, int y)
			: _x(x), _y(y)
		{}

		Point()
			: Point(0, 0)
		{}

	public:
		void SetX(int x) { _x = x; }
		int GetX() const { return _x; }

		void SetY(int y) { _y = y; }
		int GetY() const { return _y; }

	private:
		int _x;
		int _y;
	};

	class PointF : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(PointF)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_x, "X", "X");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_y, "Y", "Y");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		PointF(float x, float y)
			: _x(x), _y(y)
		{}

		PointF()
			: PointF(0.f, 0.f)
		{}

	public:
		void SetX(float x) { _x = x; }
		float GetX() const { return _x; }

		void SetY(float y) { _y = y; }
		float GetY() const { return _y; }

	private:
		float _x;
		float _y;
	};
};

#endif // _POINT_HEADER_
