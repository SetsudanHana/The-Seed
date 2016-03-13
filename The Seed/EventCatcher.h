#pragma once

#include "stdafx.h"

#include "KeyboardInput.h"
#include "Log.h"

namespace input {

	class EventCatcher
	{
	public:

		EventCatcher();
		EventCatcher(const EventCatcher&);
		~EventCatcher();

		bool catchEvents();
		void setInput(const std::shared_ptr<KeyboardInput>& input);

	private:

		std::shared_ptr<KeyboardInput> mInput;
		SDL_Event mEvent;
	};

}

