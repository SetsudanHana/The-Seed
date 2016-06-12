#pragma once

#include "stdafx.h"

#include "Log.h"

#include "VertexBufferObject.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "Shader.h"
#include "Texture.h"

#include "VertexBufferObjectGenerator.h"
#include "IndexBufferObjectGenerator.h"
#include "VertexArrayObjectBuilder.h"
#include "TextureLoader.h"
#include "ShaderLoader.h"

#include "Drawable.h"
#include "Model2D.h"

namespace gl {

	class GLContextLibrary {

		public:
			GLContextLibrary();
			GLContextLibrary(const GLContextLibrary&);
			~GLContextLibrary();

			int createVBO(float pointsArray[], unsigned & size, VertexBufferObject::VertexBufferObjectType & type);
			int createIBO(unsigned short pointsArray[], unsigned & size, GLenum & type);
			int createVAO(std::vector<std::shared_ptr<VertexBufferObject>> vbos);
			int createVAO(std::vector<int> vboIds);

			int createTexture(std::string name);
			int createShader(std::string name);

			std::shared_ptr<VertexBufferObject> getVBO(const int& id);
			std::shared_ptr<IndexBufferObject> getIBO(const int& id);
			std::shared_ptr<VertexArrayObject> getVAO(const int& id);
			std::shared_ptr<Texture> getTexture(const int& id);
			std::shared_ptr<Shader> getShader(const int& id);

			std::shared_ptr<Drawable> createDrawable(std::shared_ptr<Texture> texture);
			std::shared_ptr<Drawable> createDrawable(const int& textureId);
			std::shared_ptr<Drawable> createDrawable(std::shared_ptr<Texture> texture, std::shared_ptr<VertexArrayObject> vao, std::shared_ptr<IndexBufferObject> ibo);
			std::shared_ptr<Drawable> createDrawable(const int& textureId, const int& vaoId, const int& iboId);

			std::shared_ptr<Model2D> createModel2D(std::shared_ptr<Texture> texture);
			std::shared_ptr<Model2D> createModel2D(std::shared_ptr<Drawable> Drawable);

		private:
			int nextId();

		private:
			std::atomic<int> mCounter;

			std::map<int, std::shared_ptr<VertexBufferObject>> mVbosMap;
			std::map<int, std::shared_ptr<IndexBufferObject>> mIbosMap;
			std::map<int, std::shared_ptr<VertexArrayObject>> mVaosMap;
			std::map<int, std::shared_ptr<Texture>> mTexturesMap;
			std::map<int, std::shared_ptr<Shader>> mShadersMap;

			utils::VertexBufferObjectGenerator mVboGenerator;
			utils::IndexBufferObjectGenerator mIboGenerator;
			utils::VertexArrayObjectBuilder mVaoGenerator;
			utils::TextureLoader mTextureLoader;
			utils::ShaderLoader mShaderLoader;
	};

}