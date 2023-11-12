#pragma once

namespace Scarlett {
class Input
{
public:
	virtual ~Input() { /* Empty. */ }

	static Input* Create();

	virtual void PollInput() = 0;
};
}
