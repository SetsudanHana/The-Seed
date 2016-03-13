#pragma once

#include "stdafx.h"

namespace input {

	class Command
	{
	public:
		Command();
		Command(const Command&);
		~Command();

		void setFunction(const std::function<void(void)>&);
		void execute();

	private:
		std::function<void(void)> mFunction;
	};

}

