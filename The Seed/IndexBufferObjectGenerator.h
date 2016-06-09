#pragma once

#include "stdafx.h"

#include "Generator.h"
#include "IndexBufferObject.h"
#include "Log.h"

namespace utils {

	class IndexBufferObjectGenerator : public Generator<gl::IndexBufferObject, short, GLenum> {

		public:
			IndexBufferObjectGenerator();
			IndexBufferObjectGenerator(const IndexBufferObjectGenerator&);
			~IndexBufferObjectGenerator();

			gl::IndexBufferObject generate(short pointsArray[], unsigned& size, GLenum& type);
	};

}