#pragma once
#include "stdafx.h"

namespace window {

	class WindowVisitor {
	public:
		virtual ~WindowVisitor() {}
		virtual void visit(const std::shared_ptr<SDL_Window>& window) = 0;
	};
		
}