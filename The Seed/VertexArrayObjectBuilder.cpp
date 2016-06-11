#include "VertexArrayObjectBuilder.h"

static std::string TAG = "VertexArrayObjectBuilder";

utils::VertexArrayObjectBuilder::VertexArrayObjectBuilder(){
}

utils::VertexArrayObjectBuilder::VertexArrayObjectBuilder(const VertexArrayObjectBuilder &){
}

utils::VertexArrayObjectBuilder::~VertexArrayObjectBuilder(){
}

gl::VertexArrayObject utils::VertexArrayObjectBuilder::build(){
	unsigned* id = new unsigned();
	glGenVertexArrays(1, id);
	std::stringstream out;
	out << "VertexArray created! Id: " << *id;
	Log::Instance()->logDebug(TAG, out.str());
	return gl::VertexArrayObject(*id);
}
