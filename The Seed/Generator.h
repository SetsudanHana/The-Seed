#pragma once

#include "stdafx.h"

namespace utils {

	template<class T, typename A, typename M>
	class Generator {
		public:
			virtual ~Generator() {
			}
			virtual std::shared_ptr<T> generate(A pointsArray[], unsigned& size, M& type) = 0;
	};

}