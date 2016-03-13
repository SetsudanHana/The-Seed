#include "KeyboardInput.h"

input::KeyboardInput::KeyboardInput() {
	for (int i = 0; i < 282; ++i) {
		mKeys[i] = false;
	}
}

input::KeyboardInput::KeyboardInput(const KeyboardInput& input)
{
}

input::KeyboardInput::~KeyboardInput()
{
}

void input::KeyboardInput::pushDown(const unsigned& n) {
	mKeys[n] = true;
}

void input::KeyboardInput::pullUp(const unsigned& n) {
	mKeys[n] = false;
}

bool input::KeyboardInput::isDown(const unsigned& n) {
	return mKeys[n];
}

void input::KeyboardInput::setFunctionOnKeyDown(const std::function<void(void)>& f, const unsigned& n) {
	Command command;
	command.setFunction(f);
	auto it = mKeysDown.find(n);

	if(it != mKeysDown.end()) {
		mKeysDown.erase(it);
	}

	mKeysDown.insert(std::pair<unsigned, Command>(n, command));

}

void input::KeyboardInput::execKeysDown() {
	for(auto& it : mKeysDown) {
		if (mKeys[it.first]) {
			it.second.execute();
		}
	}
}