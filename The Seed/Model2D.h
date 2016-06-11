#pragma once

#include "stdafx.h"

#include "Texture.h"
#include "VertexArrayObject.h"
#include "IndexBufferObject.h"

namespace gl {

	class Model2D {

		public:
			Model2D();
			Model2D(std::shared_ptr<gl::Texture> texture, std::shared_ptr<gl::VertexArrayObject> vao, std::shared_ptr<gl::IndexBufferObject> ibo);
			Model2D(const Model2D&);
			~Model2D();

			void draw(unsigned& sampler);

			void scale(const glm::vec2& vec);
			void rotate(const float& angle);
			void translate(const glm::vec2& vec);

		private:
			std::shared_ptr<gl::Texture> mTexture;
			std::shared_ptr<gl::VertexArrayObject> mVao;
			std::shared_ptr<gl::IndexBufferObject> mIbo;
			glm::mat4 mWorldMatrix;
	};

}