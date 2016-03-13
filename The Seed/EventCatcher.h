#pragma once

#include "stdafx.h"

#include "Input.h"
#include "Log.h"

namespace input {

	class EventCatcher
	{
	public:

		EventCatcher();
		EventCatcher(const EventCatcher&);
		~EventCatcher();

		bool catchEvents();
		void setInput(const std::shared_ptr<Input>& input);

	private:

		std::shared_ptr<Input> mInput;
		SDL_Event mEvent;
	};

}

