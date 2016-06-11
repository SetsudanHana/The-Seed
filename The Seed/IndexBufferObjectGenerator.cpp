#include "IndexBufferObjectGenerator.h"

static std::string TAG = "IndexBufferObjectGenerator";

utils::IndexBufferObjectGenerator::IndexBufferObjectGenerator(){
}

utils::IndexBufferObjectGenerator::IndexBufferObjectGenerator(const IndexBufferObjectGenerator &){
}

utils::IndexBufferObjectGenerator::~IndexBufferObjectGenerator(){
}

gl::IndexBufferObject utils::IndexBufferObjectGenerator::generate(unsigned short pointsArray[], unsigned & size, GLenum & type){
	unsigned* id = new unsigned();
	glGenBuffers(1, id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(short), pointsArray, GL_STATIC_DRAW);

	std::stringstream out;
	out << "IndexBufefr created! Id: " << *id;
	Log::Instance()->logDebug(TAG, out.str());

	return gl::IndexBufferObject(*id, size, type);
}
