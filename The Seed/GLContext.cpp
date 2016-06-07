#include "GLContext.h"

const std::string gl::GLContext::TAG = "GLContext";

struct GLContextDeleter {
	inline void operator()(SDL_GLContext* glContext) {
		glDisable(GL_DEPTH_TEST);
		SDL_GL_DeleteContext(*glContext);
		utils::Log::Instance()->logDebug(gl::GLContext::TAG, "OpenGl context removed");
	}
};

gl::GLContext::GLContext() {
}

gl::GLContext::GLContext(const GLContext &) {
}

gl::GLContext::~GLContext() {
}

bool gl::GLContext::isInitialized() {
	return initlialized;
}

bool gl::GLContext::init(const std::shared_ptr<window::Window>& window) {
	if (window == nullptr) {
		utils::Log::Instance()->logError(TAG, "Window is not initialized");
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_FRAMEBUFFER_SRGB_CAPABLE, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

	gl::GLContext::GLContextCreatorWindowVisitor visitor;
	window->accept(visitor);
	std::unique_ptr<SDL_GLContext, std::function<void(SDL_GLContext*)>> ptr(&visitor.mGlContext, GLContextDeleter());
	mGlContext = std::move(ptr);

	if (!mGlContext) {
		utils::Log::Instance()->logError(TAG, "OpenGl context is not initialized");
		return false;
	}

	const unsigned char *version = glGetString(GL_VERSION);
	if (!version) {
		utils::Log::Instance()->logError(TAG, "Getting OGL version error");
		return false;
	}

	utils::Log::Instance()->logDebug(TAG, (char*)version);

	GetWindowVisitor getWindowVisitor;
	window->accept(getWindowVisitor);

 	SDL_GL_MakeCurrent(getWindowVisitor.mWindow.get(), *mGlContext);

	glewExperimental = GL_TRUE;

	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		utils::Log::Instance()->logError(TAG, (char*)glewGetErrorString(err));
		return false;
	}
	utils::Log::Instance()->logDebug(TAG, (char*)glewGetString(GLEW_VERSION));

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	initlialized = true;
	return true;
}

void gl::GLContext::enableDebug() {
	if (glDebugMessageCallbackARB != NULL) {
		utils::Log::Instance()->logInfo(TAG, "Enabling OpenGl debug");
		glDebugMessageCallbackARB(&gl::GLContext::ErrorCallback, NULL);
		glEnable(GL_DEBUG_OUTPUT);
	}
}
