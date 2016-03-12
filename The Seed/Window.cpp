#include "Window.h"

struct SDLWindowDeleter {
	inline void operator()(SDL_Window* window) {
		SDL_DestroyWindow(window);
	}
};

window::Window::Window(){
}

window::Window::Window(const Window &){
}

window::Window::~Window(){
}

bool window::Window::init() {
	this->mWindow = std::shared_ptr<SDL_Window>(SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL), SDLWindowDeleter());

	if (!this->mWindow) {
		return false;
	}

	return true;
}

void window::Window::accept(WindowVisitor& visitor) {
	visitor.visit(mWindow);
}