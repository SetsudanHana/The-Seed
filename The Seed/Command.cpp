#include "Command.h"

input::Command::Command()
{
}

input::Command::Command(const Command& other)
{
	mFunction = other.mFunction;
}

input::Command::~Command()
{
}

void input::Command::execute() {
	if(mFunction) {
		mFunction();
	}
}

void input::Command::setFunction(const std::function<void(void)>& function) {
	mFunction = function;
}