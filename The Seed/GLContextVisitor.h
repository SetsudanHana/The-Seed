#pragma once

#include "stdafx.h"

namespace gl {

	class GLContextVisitor {
		public:
			virtual ~GLContextVisitor() {}
			virtual void visit(const std::shared_ptr<SDL_GLContext> glContext) = 0;
	};

}