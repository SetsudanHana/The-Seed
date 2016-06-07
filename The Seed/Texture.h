#pragma once

#include "stdafx.h"

#include "Log.h"

namespace gl {

	class Texture {
	
		public:
			Texture();
			Texture(unsigned&, unsigned&, unsigned&);
			Texture(const Texture&);
			~Texture();

			void useTexture(const unsigned& sampler);
			unsigned getHeight();
			unsigned getWidth();

		private:
			std::unique_ptr<unsigned, std::function<void(unsigned int*)>> mTextureId;
			unsigned mHeight;
			unsigned mWidth;
	};

}