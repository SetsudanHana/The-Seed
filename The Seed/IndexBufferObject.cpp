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

gl::IndexBufferObject::IndexBufferObject(unsigned & iboId, IndexBufferObjectType & type){
	std::unique_ptr<unsigned int, std::function<void(unsigned int*)>> ptr(&iboId, IndesBufferObjectDeleter());
	mIboId = std::move(ptr);
	mType = type;
}

gl::IndexBufferObject::IndexBufferObject(const IndexBufferObject &){
}

gl::IndexBufferObject::~IndexBufferObject(){
}

void gl::IndexBufferObject::useIBO(){
}

gl::IndexBufferObject::IndexBufferObjectType gl::IndexBufferObject::getType(){
	return mType;
}
