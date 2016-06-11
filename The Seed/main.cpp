#include "stdafx.h"

#include "KeyboardInput.h"
#include "EventCatcher.h"
#include "Window.h"
#include "WindowSizeVisitor.h"
#include "GLContext.h"
#include "Renderer.h"

#include "TextureLoader.h"
#include "Texture.h"

#include "ShaderLoader.h"
#include "Shader.h"

#include "VertexBufferObjectGenerator.h"
#include "VertexBufferObject.h"

#include "IndexBufferObjectGenerator.h"
#include "IndexBufferObject.h"

#include "VertexArrayObjectBuilder.h"
#include "VertexArrayObject.h"

#include "Defs.h"

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

	auto textureLoader = std::make_unique<utils::TextureLoader>();
	auto mario = textureLoader->load("mario.png");

	auto shaderLoader = std::make_unique<utils::ShaderLoader>();
	auto shader = shaderLoader->load("test");

	auto vbog = std::make_unique<utils::VertexBufferObjectGenerator>();
	float position[] = { -100, 100, 100, 100, 100, -100, -100, -100 };
	unsigned positionSize = 4;
	auto positionType = gl::VertexBufferObject::POSITION_2;
	auto positionVbo = vbog->generate(position, positionSize, positionType);

	float texture[] = { 0, 1, 1, 1, 1, 0, 0, 0 };
	unsigned textureSize = 4;
	auto textureType = gl::VertexBufferObject::TEXTURE_COORDS;
	auto textureVbo = vbog->generate(texture, textureSize, textureType);

	auto ibog = std::make_unique<utils::IndexBufferObjectGenerator>();

	unsigned short index[] = { 0, 1, 2, 0, 2, 3 };
	unsigned indexSize = 6;
	GLenum indexType = GL_TRIANGLES;
	auto indexBuffer = ibog->generate(index, indexSize, indexType);

	auto vaob = std::make_unique<utils::VertexArrayObjectBuilder>();
	auto vao = vaob->build();

	vao->bindVbo(positionVbo);
	vao->bindVbo(textureVbo);

	auto matrix = glm::ortho(-(float)WINDOW_WIDTH/2, (float)WINDOW_WIDTH/2, -(float)WINDOW_HEIGHT/2, (float)WINDOW_HEIGHT/2, 0.0f, 1.0f);

	while (!end) {
		end = eventCatcher->catchEvents();
		input->execKeysDown();

		renderer->clear(glm::vec4(0.8f, 0.8f, 0.8f, 1.0f));
		
		shader->useProgram();
		shader->setMatrix4(matrix, "matrix");
		shader->setSampler(0, "sampler");

		mario->useTexture(0);

		vao->useVAO();
		indexBuffer->useIBO();

		renderer->swap(window);
	}

	return 0;
}