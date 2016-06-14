#include "GLContextLibrary.h"

static std::string TAG = "GLContextLibrary";

gl::GLContextLibrary::GLContextLibrary(){
	mCounter = 0;
}

gl::GLContextLibrary::GLContextLibrary(const GLContextLibrary &){
}

gl::GLContextLibrary::~GLContextLibrary(){
}

int gl::GLContextLibrary::createVBO(float pointsArray[], unsigned & size, VertexBufferObject::VertexBufferObjectType & type){
	auto vbo = mVboGenerator.generate(pointsArray, size, type);
	if (!vbo) {
		utils::Log::Instance()->logError(TAG, "Could not create VBO");
		return -1;
	}
	int id = nextId();
	mVbosMap.insert(std::pair<int, std::shared_ptr<gl::VertexBufferObject>>(id, vbo));
	return id;
}

int gl::GLContextLibrary::createDynamicVBO(float pointsArray[], unsigned & size, VertexBufferObject::VertexBufferObjectType & type) {
	auto vbo = mDynamicVboGenerator.generate(pointsArray, size, type);
	if (!vbo) {
		utils::Log::Instance()->logError(TAG, "Could not create dynamic VBO");
		return -1;
	}
	int id = nextId();
	mVbosMap.insert(std::pair<int, std::shared_ptr<gl::VertexBufferObject>>(id, std::static_pointer_cast<gl::VertexBufferObject>(vbo)));
	return id;
}

int gl::GLContextLibrary::createIBO(unsigned short pointsArray[], unsigned & size, GLenum & type){
	auto ibo = mIboGenerator.generate(pointsArray, size, type);
	if (!ibo) {
		utils::Log::Instance()->logError(TAG, "Could not create IBO");
		return -1;
	}
	int id = nextId();
	mIbosMap.insert(std::pair<int, std::shared_ptr<gl::IndexBufferObject>>(id, ibo));
	return id;
}

int gl::GLContextLibrary::createVAO(std::vector<std::shared_ptr<VertexBufferObject>> vbos){
	auto vao = mVaoGenerator.build();
	if (!vao) {
		utils::Log::Instance()->logError(TAG, "Could not create VAO");
		return -1;
	}

	for (unsigned i = 0; i < vbos.size(); ++i) {
		vao->bindVbo(vbos.at(i));
	}

	int id = nextId();
	mVaosMap.insert(std::pair<int, std::shared_ptr<gl::VertexArrayObject>>(id, vao));
	return id;
}

int gl::GLContextLibrary::createVAO(std::vector<int> vboIds) {
	std::vector<std::shared_ptr<gl::VertexBufferObject>> vbos;
	for (unsigned i = 0; i < vboIds.size(); ++i) {
		auto vbo = mVbosMap[vboIds.at(i)];
		if (vbo) {
			vbos.push_back(vbo);
		}
	}
	return createVAO(vbos);
}

int gl::GLContextLibrary::createTexture(std::string name) {
	auto texture = mTextureLoader.load(name);
	if (!texture) {
		utils::Log::Instance()->logError(TAG, "Could not create Texture");
		return -1;
	}

	int id = nextId();
	mTexturesMap.insert(std::pair<int, std::shared_ptr<gl::Texture>>(id, texture));
	return id;
}

int gl::GLContextLibrary::createShader(std::string name) {
	auto shader = mShaderLoader.load(name);
	if (!shader) {
		utils::Log::Instance()->logError(TAG, "Could not create Shader");
		return -1;
	}
	int id = nextId();
	mShadersMap.insert(std::pair<int, std::shared_ptr<gl::Shader>>(id, shader));
	return id;
}

std::shared_ptr<gl::VertexBufferObject> gl::GLContextLibrary::getVBO(const int & id) {
	return mVbosMap[id];
}

std::shared_ptr<gl::DynamicVertexBufferObject> gl::GLContextLibrary::getDynamicVBO(const int & id)
{
	return std::static_pointer_cast<gl::DynamicVertexBufferObject>(mVbosMap[id]);
}

std::shared_ptr<gl::IndexBufferObject> gl::GLContextLibrary::getIBO(const int & id) {
	return mIbosMap[id];
}

std::shared_ptr<gl::VertexArrayObject> gl::GLContextLibrary::getVAO(const int & id) {
	return mVaosMap[id];
}

std::shared_ptr<gl::Texture> gl::GLContextLibrary::getTexture(const int & id) {
	return mTexturesMap[id];
}

std::shared_ptr<gl::Shader> gl::GLContextLibrary::getShader(const int & id) {
	return mShadersMap[id];
}

std::shared_ptr<gl::Drawable> gl::GLContextLibrary::createDrawable(std::shared_ptr<Texture> texture) {
	float halfWidth = texture->getWidth() / 2.0f;
	float halfHeight = texture->getHeight() / 2.0f;

	float positionPoints[] = { -halfWidth, halfHeight, halfWidth, halfHeight, halfWidth, -halfHeight, -halfWidth, -halfHeight };
	unsigned positionSize = 4;
	auto positionType = gl::VertexBufferObject::POSITION_2;
	auto positionVboId = createVBO(positionPoints, positionSize, positionType);

	float texturePoints[] = { 0, 1, 1, 1, 1, 0, 0, 0 };
	unsigned textureSize = 4;
	auto textureType = gl::VertexBufferObject::TEXTURE_COORDS;
	auto textureVboId = createVBO(texturePoints, textureSize, textureType);

	unsigned short index[] = { 0, 1, 2, 0, 2, 3 };
	unsigned indexSize = 6;
	GLenum indexType = GL_TRIANGLES;
	auto iboId = createIBO(index, indexSize, indexType);

	std::vector<int> vboIds = { positionVboId, textureVboId };
	
	auto vaoId = createVAO(vboIds);

	return std::shared_ptr<Drawable>(new gl::Drawable(texture, getVAO(vaoId), getIBO(iboId)));
}

std::shared_ptr<gl::Drawable> gl::GLContextLibrary::createDrawable(const int & textureId) {
	auto texture = getTexture(textureId);
	if (texture) {
		return createDrawable(texture);
	}
	return nullptr;
}

std::shared_ptr<gl::Drawable> gl::GLContextLibrary::createDrawable(std::shared_ptr<Texture> texture, std::shared_ptr<VertexArrayObject> vao, std::shared_ptr<IndexBufferObject> ibo) {
	return std::shared_ptr<Drawable>(new gl::Drawable(texture, vao, ibo));
}

std::shared_ptr<gl::Drawable> gl::GLContextLibrary::createDrawable(const int & textureId, const int & vaoId, const int & iboId) {
	auto texture = getTexture(textureId);
	auto vao = getVAO(vaoId);
	auto ibo = getIBO(iboId);
	if (texture && vao && ibo) {
		return createDrawable(texture, vao, ibo);
	}
	return nullptr;
}

std::shared_ptr<gl::Model2D> gl::GLContextLibrary::createModel2D(std::shared_ptr<Texture> texture) {
	return std::shared_ptr<Model2D>(new Model2D(createDrawable(texture)));
}

std::shared_ptr<gl::Model2D> gl::GLContextLibrary::createModel2D(std::shared_ptr<Drawable> drawable) {
	return std::shared_ptr<Model2D>(new Model2D(drawable));
}

int gl::GLContextLibrary::nextId(){
	return ++mCounter;
}
