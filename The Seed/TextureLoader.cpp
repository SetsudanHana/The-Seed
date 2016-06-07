#include "TextureLoader.h"

static std::string TAG = "TextureLoader";

utils::TextureLoader::TextureLoader(){
}

utils::TextureLoader::TextureLoader(const TextureLoader &){
}

utils::TextureLoader::~TextureLoader(){
}

gl::Texture utils::TextureLoader::load(const std::string& name){
	UINT texture = 0;
	std::string path = TEXTURE_DIRECTORY + name;
	FIBITMAP* bitmap = FreeImage_Load(FreeImage_GetFileType(path.c_str()), path.c_str());

	if (!bitmap) {
		utils::Log::Instance()->logError(TAG, "Failed to load texture: " + path);
		return gl::Texture();
	}

	FIBITMAP *pImage = FreeImage_ConvertTo32Bits(bitmap);
	unsigned nWidth = FreeImage_GetWidth(pImage);
	unsigned nHeight = FreeImage_GetHeight(pImage);

	FreeImage_Unload(bitmap);

	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
		0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

	FreeImage_Unload(pImage);

	return gl::Texture(texture, nWidth, nHeight);
}
