#include "IndexBufferObject.h"

static std::string TAG = "IndexBufferObject";

struct IndexBufferObjectDeleter {
	inline void operator()(unsigned* iboId) {
		std::stringstream out;
		out << "Remove IBO: " << *iboId;
		utils::Log::Instance()->logDebug(TAG, out.str());
		glDeleteBuffers(1, iboId);
	}
};

gl::IndexBufferObject::IndexBufferObject(){
}

gl::IndexBufferObject::IndexBufferObject(unsigned & iboId, unsigned & size, GLenum& mode) {
	std::unique_ptr<unsigned int, std::function<void(unsigned int*)>> ptr(&iboId, IndexBufferObjectDeleter());
	mIboId = std::move(ptr);
	mSize = size;
	mMode = mode;
}

gl::IndexBufferObject::IndexBufferObject(const IndexBufferObject &){
}

gl::IndexBufferObject::~IndexBufferObject(){
}

void gl::IndexBufferObject::useIBO(){
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *mIboId);
	glDrawElements(mMode, mSize, GL_UNSIGNED_SHORT, (void*)0);
}
