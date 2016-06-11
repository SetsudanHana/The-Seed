#pragma once

#include "stdafx.h"

namespace utils {

	template<class T>
	class Loader {
		public:
			virtual ~Loader() {}
			virtual std::shared_ptr<T> load(const std::string& name) = 0;
	};

}