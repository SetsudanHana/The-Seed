#pragma once

#include "stdafx.h"
#include "WindowVisitor.h"

namespace window {

	class WindowSizeVisitor : public WindowVisitor {

	public:
		WindowSizeVisitor();
		WindowSizeVisitor(const WindowSizeVisitor&);
		~WindowSizeVisitor();

		void visit(const std::shared_ptr<SDL_Window>& window);

		int getHeight();
		int getWidth();

	private:
		int mHeight;
		int mWidth;
	};

}