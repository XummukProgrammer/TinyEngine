#ifndef _INTERFACE_LAYOUT_HEADER_
#define _INTERFACE_LAYOUT_HEADER_

namespace TinyEngine
{
	// Слой (Хранит и работает с объектами).
	class ILayout
	{
	public:
		ILayout() = default;
		virtual ~ILayout() = default;

	public:
		// Окно обновляется.
		virtual void OnWindowUpdated() {}
		// Окно рисуется.
		virtual void OnWindowDrawed() {}
		
		// Получить кол-во объектов.
		virtual size_t GetObjectsCount() const { return 0; }
	};
}

#endif // _INTERFACE_LAYOUT_HEADER_
