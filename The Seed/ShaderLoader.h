#pragma once

#include "stdafx.h"

#include "Loader.h"
#include "Shader.h"
#include "Log.h"
#include "Defs.h"

namespace utils {

	class ShaderLoader : public Loader<gl::Shader> {

		public:
			ShaderLoader();
			ShaderLoader(const ShaderLoader&);
			~ShaderLoader();

			gl::Shader load(const std::string name);

		private:
			bool checkShaderErrors(const unsigned&);
			std::string loadShaderFile(const std::string&);
	};

}