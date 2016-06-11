#include "Model2D.h"

gl::Model2D::Model2D(){
}

gl::Model2D::Model2D(std::shared_ptr<gl::Texture> texture, std::shared_ptr<gl::VertexArrayObject> vao, std::shared_ptr<gl::IndexBufferObject> ibo) {
	mWorldMatrix = glm::mat4(1.0f);
	mTexture = texture;
	mVao = vao;
	mIbo = ibo;
}

gl::Model2D::Model2D(const Model2D &){
}

gl::Model2D::~Model2D(){
}

void gl::Model2D::draw(unsigned & sampler) {
	mTexture->useTexture(sampler);
	mVao->useVAO();
	mIbo->useIBO();
}

void gl::Model2D::scale(const glm::vec2& vec){
	mWorldMatrix = glm::scale(mWorldMatrix, glm::vec3(vec, 0.0f));
}

void gl::Model2D::rotate(const float& angle){
	mWorldMatrix = glm::rotate(mWorldMatrix, angle, glm::vec3(0.0f, 0.0f, 1.0f));
}

void gl::Model2D::translate(const glm::vec2& vec){
	mWorldMatrix = glm::translate(mWorldMatrix, glm::vec3(vec, 0.0f));
}
