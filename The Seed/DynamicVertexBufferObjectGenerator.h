#pragma once

#include "stdafx.h"

#include "DynamicVertexBufferObject.h"
#include "Generator.h"

namespace utils {

	class DynamicVertexBufferObjectGenerator : public Generator<gl::DynamicVertexBufferObject, float, gl::VertexBufferObject::VertexBufferObjectType> {

		public:
			DynamicVertexBufferObjectGenerator();
			DynamicVertexBufferObjectGenerator(const DynamicVertexBufferObjectGenerator&);
			~DynamicVertexBufferObjectGenerator();

			std::shared_ptr<gl::DynamicVertexBufferObject> generate(float pointsArray[], unsigned& size, gl::VertexBufferObject::VertexBufferObjectType& type);

	};

}
