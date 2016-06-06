#pragma once

#include "stdafx.h"

#include "GLContext.h"
#include "Window.h"
#include "Log.h"

namespace gl {

	class Renderer {

		public:
			Renderer();
			Renderer(const Renderer&);
			~Renderer();

			bool bindWith(std::shared_ptr<GLContext> glContext);

			void clear(const glm::vec4& color);
			void swap(std::shared_ptr<window::Window> window);

		private:
			std::shared_ptr<GLContext> mGlContext;

		private:

			class GetWindowVisitor : public window::WindowVisitor {
				public:
					std::shared_ptr<SDL_Window> mWindow;

					void visit(const std::shared_ptr<SDL_Window> window) {
						this->mWindow = window;
					}
			};
	};

}