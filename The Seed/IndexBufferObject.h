#pragma once

#include "stdafx.h"

#include "Log.h"

namespace utils {
	class IndexBufferObjectGenerator;
}

namespace gl {

	class IndexBufferObject {

		friend class utils::IndexBufferObjectGenerator;

		private:
			IndexBufferObject();
			IndexBufferObject(unsigned&, unsigned&, GLenum&);
			IndexBufferObject(const IndexBufferObject&);
		public:
			~IndexBufferObject();

			void useIBO();

		private:
			unsigned mSize;
			GLenum mMode;
			std::unique_ptr<unsigned, std::function<void(unsigned int*)>> mIboId;

	};

}