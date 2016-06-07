#pragma once

#include "stdafx.h"

#include "Log.h"
#include "Window.h"
#include "WindowVisitor.h"

namespace gl {

	class GLContext {
		public:
			static const std::string TAG;

		public:
			GLContext();
			GLContext(const GLContext&);
			~GLContext();

			bool isInitialized();
			bool init(const std::shared_ptr<window::Window>& window);
			void enableDebug();

		private:
			static void APIENTRY ErrorCallback(
				GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
				const GLchar *message, const void *userParam) {
				utils::Log::Instance()->logError(TAG, message);
			}

		private:
			std::unique_ptr<SDL_GLContext, std::function<void(SDL_GLContext*)>> mGlContext;
			bool initlialized = false;

		private:
			class GLContextCreatorWindowVisitor : public window::WindowVisitor {
				public:
					SDL_GLContext mGlContext;

					void visit(const std::shared_ptr<SDL_Window> window) {
						this->mGlContext = SDL_GL_CreateContext(window.get());
					}
			};

			class GetWindowVisitor : public window::WindowVisitor {
				public:
					std::shared_ptr<SDL_Window> mWindow;

					void visit(const std::shared_ptr<SDL_Window> window) {
						this->mWindow = window;
					}
			};

	};

}
