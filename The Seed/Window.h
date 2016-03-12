#pragma once

#include "Defs.h"
#include "WindowVisitor.h"
namespace core {

	class Window {
	
	public:
	
		Window();
		Window(const Window&);
		~Window();

		bool init();
		void accept(WindowVisitor& visitor);

		unsigned getHeight();
		unsigned getWidth();

	private:
		std::shared_ptr<SDL_Window> mWindow;
		unsigned mWidth = WINDOW_WIDTH;
		unsigned mHeight = WINDOW_HEIGHT;

	};
}