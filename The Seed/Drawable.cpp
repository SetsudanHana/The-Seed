#include "Drawable.h"

gl::Drawable::Drawable(){
}

gl::Drawable::Drawable(const Drawable &){
}

gl::Drawable::Drawable(std::shared_ptr<Texture> texture, std::shared_ptr<VertexArrayObject> vao, std::shared_ptr<IndexBufferObject> ibo){
	mTexture = texture;
	mVao = vao;
	mIbo = ibo;
}

gl::Drawable::~Drawable(){
}

void gl::Drawable::draw(const unsigned & sampler){
	mTexture->useTexture(sampler);
	mVao->useVAO();
	mIbo->useIBO();
}
