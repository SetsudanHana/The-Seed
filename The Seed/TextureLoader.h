#pragma once

#include "Loader.h"
#include "Texture.h"
#include "Log.h"
#include "Defs.h"

namespace utils {

	class TextureLoader : public Loader<gl::Texture> {

		public:
			TextureLoader();
			TextureLoader(const TextureLoader&);
			~TextureLoader();

			std::shared_ptr<gl::Texture> load(const std::string& name);

	};

}