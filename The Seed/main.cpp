#include "stdafx.h"

#include "KeyboardInput.h"
#include "EventCatcher.h"
#include "Window.h"
#include "WindowSizeVisitor.h"
#include "GLContext.h"
#include "Renderer.h"

#include "Texture.h"
#include "Shader.h"

#include "GLContextLibrary.h"

#include "Defs.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	auto window = std::make_shared<window::Window>();
	window->init();

	auto glContext = std::make_shared<gl::GLContext>();
	glContext->init(window);

	auto glContextLibrary = std::make_unique<gl::GLContextLibrary>();

	auto renderer = std::make_shared<gl::Renderer>();
	renderer->bindWith(glContext);

	bool end = false;

	auto input = std::make_shared<input::KeyboardInput>();
	auto eventCatcher = std::make_unique<input::EventCatcher>();
	eventCatcher->setInput(input);

	input->setFunctionOnKeyDown([&end]() {
		end = true;
	}, SDL_GetScancodeFromKey(SDLK_ESCAPE));

	auto shaderId = glContextLibrary->createShader("test");

	auto textureId = glContextLibrary->createTexture("mario.png");
	auto marioModel = glContextLibrary->createModel2D(glContextLibrary->getTexture(textureId));

	auto shader = glContextLibrary->getShader(shaderId);

	auto matrix = glm::ortho(-(float)WINDOW_WIDTH/2, (float)WINDOW_WIDTH/2, -(float)WINDOW_HEIGHT/2, (float)WINDOW_HEIGHT/2, 0.0f, 1.0f);

	unsigned sampler = 0;

	while (!end) {
		end = eventCatcher->catchEvents();
		input->execKeysDown();

		renderer->clear(glm::vec4(0.8f, 0.8f, 0.8f, 1.0f));
		
		shader->useProgram();
		shader->setMatrix4(matrix, "matrix");
		shader->setSampler(sampler, "sampler");

		marioModel->draw(sampler);

		renderer->swap(window);
	}

	return 0;
}