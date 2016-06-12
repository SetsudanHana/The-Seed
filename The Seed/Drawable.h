#pragma once

#include "stdafx.h"

#include "VertexArrayObject.h"
#include "IndexBufferObject.h"
#include "Texture.h"

namespace gl {

	class Drawable {

		private:
			Drawable();
			Drawable(const Drawable&);
			Drawable(std::shared_ptr<Texture> texture, std::shared_ptr<VertexArrayObject> vao, std::shared_ptr<IndexBufferObject> ibo);

		public:
			~Drawable();

			void draw(const unsigned& sampler);

		private:
			std::shared_ptr<gl::Texture> mTexture;
			std::shared_ptr<gl::VertexArrayObject> mVao;
			std::shared_ptr<gl::IndexBufferObject> mIbo;
	};

}