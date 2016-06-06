#pragma once

#include "stdafx.h"

namespace utils {

	template<class T>
	class Loader {
		public:
			virtual ~Loader() {}
			virtual T load(const std::string name) = 0;
	};

}