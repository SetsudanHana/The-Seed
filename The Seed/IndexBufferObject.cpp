#include "IndexBufferObject.h"

static std::string TAG = "IndexBufferObject";

struct IndesBufferObjectDeleter {
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
	std::unique_ptr<unsigned int, std::function<void(unsigned int*)>> ptr(&iboId, IndesBufferObjectDeleter());
	mIboId = std::move(ptr);
	mSize = size;
}

gl::IndexBufferObject::IndexBufferObject(const IndexBufferObject &){
}

gl::IndexBufferObject::~IndexBufferObject(){
}

void gl::IndexBufferObject::useIBO(){
	const size_t intHashcode = typeid(int).hash_code();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *mIboId);
	glDrawElements(mMode, mSize, GL_UNSIGNED_SHORT, (void*)0);
}
