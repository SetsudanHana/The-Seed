#include "VertexArrayObjectBuilder.h"

static std::string TAG = "VertexArrayObjectBuilder";

utils::VertexArrayObjectBuilder::VertexArrayObjectBuilder(){
}

utils::VertexArrayObjectBuilder::VertexArrayObjectBuilder(const VertexArrayObjectBuilder &){
}

utils::VertexArrayObjectBuilder::~VertexArrayObjectBuilder(){
}

gl::VertexArrayObject utils::VertexArrayObjectBuilder::build(){
	unsigned id;
	glGenVertexArrays(1, &id);
	Log::Instance()->logDebug(TAG, "VertexArray created! Id: " + id);
	return gl::VertexArrayObject(id);
}
