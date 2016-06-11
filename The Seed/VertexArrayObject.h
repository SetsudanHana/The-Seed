#pragma once

#include "stdafx.h"

#include "VertexBufferObject.h"
#include "Log.h"

namespace gl {

	class VertexArrayObject {

		public:
			VertexArrayObject();
			VertexArrayObject(unsigned&);
			VertexArrayObject(const VertexArrayObject&);
			~VertexArrayObject();

			void bindVbo(VertexBufferObject& vbo);
			void useVAO();

			void enableVBO(const VertexBufferObject::VertexBufferObjectType& type);
			void disableVBO(const VertexBufferObject::VertexBufferObjectType& type);

		private:
			std::unique_ptr<unsigned, std::function<void(unsigned int*)>> mVaoId;
	};

}