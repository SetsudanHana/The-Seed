#include "TextureLoader.h"

static std::string TAG = "TextureLoader";

utils::TextureLoader::TextureLoader(){
}

utils::TextureLoader::TextureLoader(const TextureLoader &){
}

utils::TextureLoader::~TextureLoader(){
}

std::shared_ptr<gl::Texture> utils::TextureLoader::load(const std::string& name){
	UINT* texture = new UINT();
	std::string path = TEXTURE_DIRECTORY + name;
	FIBITMAP* bitmap = FreeImage_Load(FreeImage_GetFileType(path.c_str()), path.c_str());

	if (!bitmap) {
		utils::Log::Instance()->logError(TAG, "Failed to load texture: " + path);
		nullptr;
	}

	FIBITMAP *pImage = FreeImage_ConvertTo32Bits(bitmap);
	unsigned nWidth = FreeImage_GetWidth(pImage);
	unsigned nHeight = FreeImage_GetHeight(pImage);

	FreeImage_Unload(bitmap);

	glGenTextures(1, texture);

	glBindTexture(GL_TEXTURE_2D, *texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
		0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

	FreeImage_Unload(pImage);

	utils::Log::Instance()->logDebug(TAG, "Created texture from path: " + path);
	return std::shared_ptr<gl::Texture>(new gl::Texture(*texture, nWidth, nHeight));
}
