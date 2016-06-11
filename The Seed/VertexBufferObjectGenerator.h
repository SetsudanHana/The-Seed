#pragma once

#include "stdafx.h"

#include "Generator.h"
#include "VertexBufferObject.h"
#include "Log.h"

namespace utils {

	class VertexBufferObjectGenerator : public Generator<gl::VertexBufferObject, float, gl::VertexBufferObject::VertexBufferObjectType> {

		public:
			VertexBufferObjectGenerator();
			VertexBufferObjectGenerator(const VertexBufferObjectGenerator&);
			~VertexBufferObjectGenerator();

			std::shared_ptr<gl::VertexBufferObject> generate(float pointsArray[], unsigned& size, gl::VertexBufferObject::VertexBufferObjectType& type);

	};

}