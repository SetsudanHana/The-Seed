#pragma once

#include "stdafx.h"

#include "Log.h"

namespace utils {
	class TextureLoader;
}

namespace gl {

	class Texture {
	
		friend class utils::TextureLoader;

		private:
			Texture();
			Texture(unsigned&, unsigned&, unsigned&);
			Texture(const Texture&);
		public:
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