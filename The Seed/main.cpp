#include "stdafx.h"

#include "KeyboardInput.h"
#include "EventCatcher.h"
#include "Window.h"
#include "WindowSizeVisitor.h"
#include "GLContext.h"
#include "Renderer.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	auto window = std::make_shared<window::Window>();
	window->init();

	auto glContext = std::make_shared<gl::GLContext>();
	glContext->init(window);

	auto renderer = std::make_shared<gl::Renderer>();
	renderer->bindWith(glContext);

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

		renderer->clear(glm::vec4(0.8f, 0.8f, 0.8f, 1.0f));
		renderer->swap(window);
	}

	return 0;
}