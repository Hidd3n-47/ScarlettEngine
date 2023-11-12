#include "sltpch.h"
#include "SDLInput.h"

#include <sdl/sdl.h>

#include "src/Engine.h"
#include "InputManager.h"

namespace Scarlett {

#if SDL_API == 1
Input* Input::Create()
{
	return new SDLInput();
}
#endif

void SDLInput::PollInput()
{
	SDL_Event evnt;
	SDL_PollEvent(&evnt);

	switch (evnt.type)
	{
	case SDL_QUIT:
		Engine::Instance()->StopRunning();
		break;
	case SDL_KEYDOWN:
		//InputManager::PressKey(evnt.key.keysym.sym);
		break;
	case SDL_KEYUP:
		//InputManager::ReleaseKey(evnt.key.keysym.sym);
		break;
	default:
		break;
	}
}

}