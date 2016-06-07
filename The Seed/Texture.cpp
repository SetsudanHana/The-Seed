#include "Texture.h"

static std::string TAG = "Texture";

struct TextureDeleter  {
	inline void operator()(unsigned* textureId) {
		std::stringstream out;
		out << "Remove texture: " << *textureId;
		utils::Log::Instance()->logDebug(TAG, out.str());
		glDeleteTextures(1, textureId);
	}
};

gl::Texture::Texture(){
}

gl::Texture::Texture(unsigned & textureId, unsigned & width, unsigned & height) {
	mHeight = height;
	mWidth = width;
	std::unique_ptr<unsigned int, std::function<void(unsigned int*)>> ptr(&textureId, TextureDeleter());
	mTextureId = std::move(ptr);
}

gl::Texture::Texture(const Texture &){
}

gl::Texture::~Texture(){
}

void gl::Texture::useTexture(const unsigned & sampler){
	glActiveTexture(GL_TEXTURE0 + sampler);
	glBindTexture(GL_TEXTURE_2D, *mTextureId.get());
}

unsigned gl::Texture::getHeight() {
	return mHeight;
}

unsigned gl::Texture::getWidth() {
	return mWidth;
}
