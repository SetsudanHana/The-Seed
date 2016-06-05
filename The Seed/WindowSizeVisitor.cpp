#include "WindowSizeVisitor.h"

window::WindowSizeVisitor::WindowSizeVisitor()
{
}

window::WindowSizeVisitor::WindowSizeVisitor(const WindowSizeVisitor &)
{
}

window::WindowSizeVisitor::~WindowSizeVisitor()
{
}

void window::WindowSizeVisitor::visit(const std::shared_ptr<SDL_Window> window){
	SDL_GetWindowSize(window.get(), &mWidth, &mHeight);
}

int window::WindowSizeVisitor::getHeight(){
	return this->mHeight;
}

int window::WindowSizeVisitor::getWidth(){
	return this->mWidth;
}
