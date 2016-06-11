#pragma once

#include "stdafx.h"

#include "VertexArrayObject.h"
#include "Log.h"

namespace utils {

	class VertexArrayObjectBuilder
	{
		public:
			VertexArrayObjectBuilder();
			VertexArrayObjectBuilder(const VertexArrayObjectBuilder&);
			~VertexArrayObjectBuilder();

			std::shared_ptr<gl::VertexArrayObject> build();

	};

}