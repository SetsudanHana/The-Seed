#include "Window.h"

static std::string TAG = "WINDOW";

struct SDLWindowDeleter {
	inline void operator()(SDL_Window* window) {
		utils::Log::Instance()->logDebug(TAG, "SDL window destroyed");
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
};

window::Window::Window(){
}

window::Window::Window(const Window &){
}

window::Window::~Window(){
}

bool window::Window::init() {
	SDL_Init(SDL_INIT_EVERYTHING);

	this->mWindow = std::shared_ptr<SDL_Window>(SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL), SDLWindowDeleter());

	if (!this->mWindow) {
		std::string error(SDL_GetError());
		utils::Log::Instance()->logError(TAG, "SDL window creation error: " + error);
		return false;
	}
	utils::Log::Instance()->logDebug(TAG, "SDL window created");

	return true;
}

void window::Window::accept(WindowVisitor& visitor) {
	visitor.visit(mWindow);
}