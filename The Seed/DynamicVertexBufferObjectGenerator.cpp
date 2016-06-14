#include "DynamicVertexBufferObjectGenerator.h"

static std::string TAG = "DynamicVertexBufferObjectGenerator";

utils::DynamicVertexBufferObjectGenerator::DynamicVertexBufferObjectGenerator() {
}

utils::DynamicVertexBufferObjectGenerator::DynamicVertexBufferObjectGenerator(const DynamicVertexBufferObjectGenerator &) {
}

utils::DynamicVertexBufferObjectGenerator::~DynamicVertexBufferObjectGenerator() {
}

std::shared_ptr<gl::DynamicVertexBufferObject> utils::DynamicVertexBufferObjectGenerator::generate(float pointsArray[], unsigned & size, gl::VertexBufferObject::VertexBufferObjectType & type) {
	unsigned* id = new unsigned();
	glGenBuffers(1, id);
	glBindBuffer(GL_ARRAY_BUFFER, *id);

	switch (type) {
	case gl::VertexBufferObject::POSITION_2:
	case gl::VertexBufferObject::TEXTURE_COORDS:
		glBufferData(GL_ARRAY_BUFFER, 2 * size * sizeof(float), pointsArray, GL_DYNAMIC_DRAW);
		break;
	}

	std::stringstream out;
	out << "DynamicVertextBuffer created! Id: " << *id;
	Log::Instance()->logDebug(TAG, out.str());

	return std::shared_ptr<gl::DynamicVertexBufferObject>(new gl::DynamicVertexBufferObject(*id, type));
}
