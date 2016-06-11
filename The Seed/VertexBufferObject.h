#pragma once

#include "stdafx.h"

#include "Log.h"

namespace utils {
	class VertexBufferObjectGenerator;
}

namespace gl {

	class VertexBufferObject {

		friend class utils::VertexBufferObjectGenerator;
		friend class VertexArrayObject;

		public:
			enum VertexBufferObjectType {
				POSITION_2,
				TEXTURE_COORDS
			};

		private:
			VertexBufferObject();
			VertexBufferObject(unsigned&, const VertexBufferObjectType&);
			VertexBufferObject(const VertexBufferObject&);
		public:
			~VertexBufferObject();

			VertexBufferObjectType getType();

		private:
			VertexBufferObjectType mType;
			std::unique_ptr<unsigned, std::function<void(unsigned int*)>> mVboId;
	};

}