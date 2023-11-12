#pragma once

#include "Input.h"

namespace Scarlett {
class SDLInput : public Input
{
public:
	virtual void PollInput() override;
};
}
