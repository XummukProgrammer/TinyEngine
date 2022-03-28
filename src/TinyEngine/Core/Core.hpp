#ifndef _CORE_HEADER_
#define _CORE_HEADER_

namespace TinyEngine
{
	class Core final
	{
	public:
		Core() = default;
		~Core() = default;

	public:
		// Запустить игровой движок.
		void Exec();
	};
}

#endif // _CORE_HEADER_
