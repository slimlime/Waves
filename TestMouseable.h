#pragma once

#include "FrameUpdateDispatcher.h"
#include "EventDispatcher.h"
#include "Mouseable.h"

using namespace hwgame;

class TestMouseable : public Mouseable
{

public:

	TestMouseable(FrameUpdateDispatcher& frameUpdateDispatcher_):
		Mouseable(frameUpdateDispatcher_),
		frameUpdateDispatcher(frameUpdateDispatcher_)
	{};

	~TestMouseable() {};

	// satisfy mouseable
	bool mouseInside(int mouseX, int mouseY) {

		// for let's say the right half of the screen is 'in'
		if (mouseX > 400)
			return true;
		else
			return false;
	};

	FrameUpdateDispatcher& frameUpdateDispatcher;
};

// for now no unit test for this one - just test it
// in the game itself