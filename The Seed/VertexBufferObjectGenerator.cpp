#include "VertexBufferObjectGenerator.h"

static std::string TAG = "VertexBufferObjectGenerator";

utils::VertexBufferObjectGenerator::VertexBufferObjectGenerator(){
}

utils::VertexBufferObjectGenerator::VertexBufferObjectGenerator(const VertexBufferObjectGenerator &){
}

utils::VertexBufferObjectGenerator::~VertexBufferObjectGenerator(){
}

gl::VertexBufferObject utils::VertexBufferObjectGenerator::generate(float pointsArray[], unsigned & size, gl::VertexBufferObject::VertexBufferObjectType & type) {
	unsigned id;
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);

	switch (type) {
		case gl::VertexBufferObject::POSITION_2:
		case gl::VertexBufferObject::TEXTURE_COORDS:
			glBufferData(GL_ARRAY_BUFFER, 2 * size * sizeof(float), pointsArray, GL_STATIC_DRAW);
			break;
	}

	Log::Instance()->logDebug(TAG, "VertextBuffer created! Id: " + id);

	return gl::VertexBufferObject(id, type);
}