#pragma once
#include "stdafx.h"

#include "Command.h"

namespace input {

	class Input
	{
	public:

		Input();
		Input(const Input&);
		~Input();

		void pushDown(const unsigned&);
		void pullUp(const unsigned&);
		bool isDown(const unsigned&);

		void setFunctionOnKeyDown(const std::function<void(void)>&, const unsigned&);
		void execKeysDown();

	private:
		bool mKeys[282];
		std::map<unsigned, Command> mKeysDown;
	};

}

