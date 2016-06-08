#pragma once

#include "stdafx.h"

#include "Log.h"

namespace gl {

	class IndexBufferObject {

		public:
			IndexBufferObject();
			IndexBufferObject(unsigned&, unsigned&, GLenum&);
			IndexBufferObject(const IndexBufferObject&);
			~IndexBufferObject();

			void useIBO();

		private:
			unsigned mSize;
			GLenum mMode;
			std::unique_ptr<unsigned, std::function<void(unsigned int*)>> mIboId;

	};

}