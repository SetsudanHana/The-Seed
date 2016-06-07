#pragma once

#include "stdafx.h"

#include "Log.h"

namespace gl {

	class VertexBufferObject {

		friend class VertexArrayObject;

		public:
			enum VertexBufferObjectType {
				POSITION_2,
				TEXTURE_COORDS
			};

		public:
			VertexBufferObject();
			VertexBufferObject(unsigned&, const VertexBufferObjectType&);
			VertexBufferObject(const VertexBufferObject&);
			~VertexBufferObject();

			VertexBufferObjectType getType();

		private:
			VertexBufferObjectType mType;
			std::unique_ptr<unsigned, std::function<void(unsigned int*)>> mVboId;
	};

}