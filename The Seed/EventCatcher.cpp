#include "EventCatcher.h"

static std::string TAG = "EventCatcher";

input::EventCatcher::EventCatcher()
{
}

input::EventCatcher::EventCatcher(const EventCatcher&)
{
}

input::EventCatcher::~EventCatcher()
{
}

bool input::EventCatcher::catchEvents() {
	if (!mInput) {
		utils::Log::Instance()->logWarning(TAG, "Input instance is not set");
		return false;
	}

	while(SDL_PollEvent(&mEvent) != 0) {
		if(mEvent.type == SDL_QUIT) {
			return true;
		}
		else if(mEvent.type == SDL_KEYDOWN ) {
			mInput->pushDown(mEvent.key.keysym.scancode);
		}
		else if( mEvent.type == SDL_KEYUP ) {
			mInput->pullUp(mEvent.key.keysym.scancode);
		}
	}
	return false;
}

void input::EventCatcher::setInput(const std::shared_ptr<Input>& input) {
	if (input != nullptr) {
		mInput = input;
	} else {
		utils::Log::Instance()->logWarning(TAG, "Trying to add NULL as a Input instance");
	}
}