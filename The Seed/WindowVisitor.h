#pragma once
#include "stdafx.h"

namespace core {

	class WindowVisitor {
	public:
		virtual void visit(const std::shared_ptr<SDL_Window>& window) = 0;
	};
		
}