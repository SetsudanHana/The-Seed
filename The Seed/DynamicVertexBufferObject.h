#pragma once

#include "stdafx.h"

#include "VertexBufferObject.h"

namespace gl {

	class DynamicVertexBufferObject : public VertexBufferObject {

		friend class VertexArrayObject;

		public:
			DynamicVertexBufferObject(unsigned& id, const VertexBufferObjectType& type) : VertexBufferObject(id, type) {
			
			}
	};

}
