#pragma once

#include "stdafx.h"

#include "Drawable.h"

namespace utils {
	class Model2DBuilder;
}

namespace gl {

	class Model2D {

		friend class utils::Model2DBuilder;

		private:
			Model2D();
			Model2D(std::shared_ptr<Drawable> drawable);
			Model2D(const Model2D&);
		public:
			~Model2D();

			void draw(unsigned& sampler);

			void scale(const glm::vec2& vec);
			void rotate(const float& angle);
			void translate(const glm::vec2& vec);

		private:
			std::shared_ptr<gl::Drawable> mDrawable;
			glm::mat4 mWorldMatrix;
	};

}