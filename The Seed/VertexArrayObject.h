#pragma once

#include "stdafx.h"

#include "VertexBufferObject.h"
#include "Log.h"

namespace utils {
	class VertexArrayObjectBuilder;
}

namespace gl {

	class VertexArrayObject {

		friend class utils::VertexArrayObjectBuilder;

		private:
			VertexArrayObject();
			VertexArrayObject(unsigned&);
			VertexArrayObject(const VertexArrayObject&);
		public:
			~VertexArrayObject();

			void bindVbo(std::shared_ptr<VertexBufferObject> vbo);
			void useVAO();

			void enableVBO(const VertexBufferObject::VertexBufferObjectType& type);
			void disableVBO(const VertexBufferObject::VertexBufferObjectType& type);

		private:
			std::unique_ptr<unsigned, std::function<void(unsigned int*)>> mVaoId;
	};

}