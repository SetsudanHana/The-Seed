#include "VertexBufferObject.h"

static std::string TAG = "VertexBufferObject";

struct VertexBufferObjectDeleter {
	inline void operator()(unsigned* vboId) {
		std::stringstream out;
		out << "Remove VBO: " << *vboId;
		utils::Log::Instance()->logDebug(TAG, out.str());
		glDeleteBuffers(1, vboId);
	}
};

gl::VertexBufferObject::VertexBufferObject(){
}

gl::VertexBufferObject::VertexBufferObject(unsigned & vboId, const VertexBufferObjectType & type){
	std::unique_ptr<unsigned int, std::function<void(unsigned int*)>> ptr(&vboId, VertexBufferObjectDeleter());
	mVboId = std::move(ptr);
	mType = type;
}

gl::VertexBufferObject::VertexBufferObject(const VertexBufferObject &){
}

gl::VertexBufferObject::~VertexBufferObject(){
}

gl::VertexBufferObject::VertexBufferObjectType gl::VertexBufferObject::getType() {
	return mType;
}
