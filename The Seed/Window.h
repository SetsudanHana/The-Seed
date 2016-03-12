#pragma once

#include "Defs.h"
#include "WindowVisitor.h"
namespace window {

	class Window {
	
	public:
	
		Window();
		Window(const Window&);
		~Window();

		bool init();
		void accept(WindowVisitor& visitor);

	private:
		std::shared_ptr<SDL_Window> mWindow;

	};
}