#include "stdafx.h"

#include "Window.h"
#include "WindowSizeVisitor.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	auto window = std::make_unique<window::Window>();
	window->init();

	return 0;
}