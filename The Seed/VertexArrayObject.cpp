#include "VertexArrayObject.h"

static std::string TAG = "VertexArrayObject";

struct VertexArrayObjectDeleter {
	inline void operator()(unsigned* vaoId) {
		std::stringstream out;
		out << "Remove VAO: " << *vaoId;
		utils::Log::Instance()->logDebug(TAG, out.str());
		glDeleteVertexArrays(1, vaoId);
	}
};

gl::VertexArrayObject::VertexArrayObject(){
}

gl::VertexArrayObject::VertexArrayObject(unsigned & vaoId){
	std::unique_ptr<unsigned int, std::function<void(unsigned int*)>> ptr(&vaoId, VertexArrayObjectDeleter());
	mVaoId = std::move(ptr);
}

gl::VertexArrayObject::VertexArrayObject(const VertexArrayObject &){
}

gl::VertexArrayObject::~VertexArrayObject(){
}

void gl::VertexArrayObject::bindVbo(std::shared_ptr<VertexBufferObject> vbo) {
	bindVbo(*vbo->mVboId, vbo->getType());
}

void gl::VertexArrayObject::bindVbo(std::shared_ptr<DynamicVertexBufferObject> vbo) {
	bindVbo(*vbo->mVboId, vbo->getType());
}

void gl::VertexArrayObject::useVAO(){
	glBindVertexArray(*mVaoId);
}

void gl::VertexArrayObject::enableVBO(const VertexBufferObject::VertexBufferObjectType & type){
	glBindVertexArray(*mVaoId);
	glEnableVertexAttribArray(type);

	std::stringstream out;
	out << "VertexBufferType: " << type << " enabled in VertexArray id: " << *mVaoId;
	utils::Log::Instance()->logDebug(TAG, out.str());
}

void gl::VertexArrayObject::disableVBO(const VertexBufferObject::VertexBufferObjectType & type){
	glBindVertexArray(*mVaoId);
	glDisableVertexAttribArray(type);

	std::stringstream out;
	out << "VertexBufferType: " << type << " disabled in VertexArray id: " << *mVaoId;
	utils::Log::Instance()->logDebug(TAG, out.str());
}

void gl::VertexArrayObject::bindVbo(const unsigned & vboId, const VertexBufferObject::VertexBufferObjectType & type) {
	glBindVertexArray(*mVaoId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	switch (type) {
	case VertexBufferObject::TEXTURE_COORDS:
	case VertexBufferObject::POSITION_2:
		glVertexAttribPointer(type, 2, GL_FLOAT, GL_FALSE, 0, NULL);
		break;
	}

	std::stringstream out;
	out << "VertexBuffer id: " << vboId << " binded to VertexArray id: " << *mVaoId;
	utils::Log::Instance()->logDebug(TAG, out.str());

	enableVBO(type);
}
