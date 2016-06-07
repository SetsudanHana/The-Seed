#pragma once

#include "stdafx.h"

#include "Log.h"
#include "Window.h"
#include "WindowVisitor.h"

namespace gl {

	class GLContext {

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
			static const std::string TAG;
			std::shared_ptr<SDL_GLContext> mGlContext;
			bool initlialized = false;

		private:
			class GLContextCreatorWindowVisitor : public window::WindowVisitor {
				public:
					std::shared_ptr<SDL_GLContext> mGlContext;

					void visit(const std::shared_ptr<SDL_Window> window) {
						this->mGlContext = std::make_shared<SDL_GLContext>(SDL_GL_CreateContext(window.get()));
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
