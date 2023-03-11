#ifndef _CONTEXT_HEADER_
#define _CONTEXT_HEADER_

#include <TinyEngine/Core/VisualObject/Transform.hpp>

#include <string>

namespace TinyEngine
{
	class Context
	{
	public:
		void SetArgc(int argc) { _argc = argc; }
		int GetArgc() const { return _argc; }

		void SetArgv(char** argv) { _argv = argv; }
		char** GetArgv() const { return _argv; }

		void SetScreenWidth(int screenWidth) { _screenWidth = screenWidth; }
		int GetScreenWidth() const { return _screenWidth; }

		void SetScreenHeight(int screenHeight) { _screenHeight = screenHeight; }
		int GetScreenHeight() const { return _screenHeight; }

		void SetWindowTitle(std::string_view windowTitle) { _windowTitle = windowTitle; }
		const std::string& GetWindowTitle() const { return _windowTitle; }

		void SetScalePixelCoef(float scalePixelCoef) { _scalePixelCoef = scalePixelCoef; }
		float GetScalePixelCoef() const { return _scalePixelCoef; }

		void SetIsDrawGizmos(bool isDrawGizmos) { _isDrawGizmos = isDrawGizmos; }
		bool IsDrawGizmos() const { return _isDrawGizmos; }

		std::shared_ptr<TinyEngine::Transform> GetRootTransform() const { return _rootTransform; }

	private:
		int _argc;
		char** _argv;
		int _screenWidth;
		int _screenHeight;
		std::string _windowTitle;
		float _scalePixelCoef;
		bool _isDrawGizmos;
		std::shared_ptr<TinyEngine::Transform> _rootTransform = std::make_shared<TinyEngine::Transform>();
	};
}

#endif // _CONTEXT_HEADER_
