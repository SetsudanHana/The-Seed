#include "stdafx.h"

#include "KeyboardInput.h"
#include "EventCatcher.h"
#include "Window.h"
#include "WindowSizeVisitor.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	auto window = std::make_unique<window::Window>();
	window->init();

	bool end = false;

	auto input = std::make_shared<input::KeyboardInput>();
	auto eventCatcher = std::make_unique<input::EventCatcher>();
	eventCatcher->setInput(input);

	input->setFunctionOnKeyDown([&end]() {
		end = true;
	}, SDL_GetScancodeFromKey(SDLK_ESCAPE));

	while (!end) {
		end = eventCatcher->catchEvents();
		input->execKeysDown();
	}

	return 0;
}