#pragma once

#include "stdafx.h"

#include "Log.h"

namespace gl {

	class IndexBufferObject {

		public:
			enum IndexBufferObjectType {
				UNSIGNED_SHORT,
				UNSIGNED_INT
			};

		public:
			IndexBufferObject();
			IndexBufferObject(unsigned&, IndexBufferObjectType&);
			IndexBufferObject(const IndexBufferObject&);
			~IndexBufferObject();

			void useIBO();
			IndexBufferObjectType getType();

		private:
			IndexBufferObjectType mType;
			std::unique_ptr<unsigned, std::function<void(unsigned int*)>> mIboId;

	};

}