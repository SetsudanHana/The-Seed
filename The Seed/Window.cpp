#include "Window.h"

struct SDLWindowDeleter {
	inline void operator()(SDL_Window* window) {
		SDL_DestroyWindow(window);
	}
};

core::Window::Window(){
}

core::Window::Window(const Window &){
}

core::Window::~Window(){
}

bool core::Window::init() {
	this->mWindow = std::shared_ptr<SDL_Window>(SDL_CreateWindow(WINDOW_TITLE, this->mWidth / 2, this->mHeight / 2, this->mWidth, this->mHeight, SDL_WINDOW_OPENGL), SDLWindowDeleter());

	if (!this->mWindow) {
		return false;
	}

	return true;
}

void core::Window::accept(WindowVisitor& visitor) {
	visitor.visit(mWindow);
}

unsigned core::Window::getHeight() {
	return this->mHeight;
}

unsigned core::Window::getWidth() {
	return this->mWidth;
}