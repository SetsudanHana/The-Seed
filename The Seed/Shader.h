#pragma once

#include "stdafx.h"

#include "Log.h"

namespace utils {
	class ShaderLoader;
}

namespace gl {

	class Shader {

		friend class utils::ShaderLoader;

		private:
			Shader();
			Shader(unsigned& program);
			Shader(const Shader&);
		public:
			~Shader();

			void useProgram();

			void setField(const float&, const std::string&);
			void setSampler(const UINT&, const std::string&);
			void setVector2(const glm::vec2&, const std::string&);
			void setVector3(const glm::vec3&, const std::string&);
			void setVector4(const glm::vec4&, const std::string&);
			void setMatrix2(const glm::mat2&, const std::string&);
			void setMatrix3(const glm::mat3&, const std::string&);
			void setMatrix4(const glm::mat4&, const std::string&);

		private:
			std::unique_ptr<unsigned, std::function<void(unsigned int*)>> mProgram;
	};

}