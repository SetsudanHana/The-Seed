#ifdef _DEBUG
#define ENABLE_GL_DEBUG 1
#else
#define ENABLE_GL_DEBUG 0
#endif

#include "Renderer.h"

static std::string TAG = "Renderer";

gl::Renderer::Renderer(){
}

gl::Renderer::Renderer(const Renderer &){
}

gl::Renderer::~Renderer(){
}

bool gl::Renderer::bindWith(std::shared_ptr<GLContext> glContext){
	if (!glContext || !glContext->isInitialized()) {
		utils::Log::Instance()->logError(TAG, "OpenGl context is not initialized");
		return false;
	}

	mGlContext = glContext;

	if (ENABLE_GL_DEBUG) {
		mGlContext->enableDebug();
	}

	return true;
}

void gl::Renderer::clear(const glm::vec4 & color){

	if (!mGlContext)
	{
		utils::Log::Instance()->logError(TAG, "OpenGl context is not bound");
		return;
	}

	glClearColor(color.x, color.y, color.z, color.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void gl::Renderer::swap(std::shared_ptr<window::Window> window){

	if (!mGlContext)
	{
		utils::Log::Instance()->logError(TAG, "OpenGl context is not bound");
		return;
	}

	GetWindowVisitor visitor;
	window->accept(visitor);
	SDL_GL_SwapWindow(visitor.mWindow.get());
}
