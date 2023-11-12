#include "sltpch.h"
#include "Engine.h"

#include <sdl/SDL.h>

namespace Scarlett {

Engine* Engine::m_instance = nullptr;

void Engine::Init()
{
	if (SDL_API)
	{
		int sdlInit = SDL_Init(SDL_INIT_EVERYTHING);

		SLT_ASSERT(sdlInit == 0, "Failed to initialise SDL.");
	}

	m_window = std::unique_ptr<Window>(Window::Create());
	//m_input->Create();
}

void Engine::Run()
{
	while (m_running)
	{
		m_window->Update();

		//m_input->PollInput();
		SDL_Event evnt;
		SDL_PollEvent(&evnt);
		switch (evnt.type)
		{
		case SDL_QUIT:
			m_running = false;
			break;
		case SDL_KEYDOWN:
			//InputManager::PressKey(evnt.key.keysym.sym);
			DLOG("pressed");
			break;
		case SDL_KEYUP:
			//InputManager::ReleaseKey(evnt.key.keysym.sym);
			break;
		case SDL_WINDOWEVENT:
			if (evnt.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
			{
				m_window->Resize(evnt.window.data1, evnt.window.data2);
			}
			break;
		default:
			break;
		}
	}
}

void Engine::Destroy()
{
	if (SDL_API)
	{
		SDL_Quit();
	}

	delete m_instance;
}

}