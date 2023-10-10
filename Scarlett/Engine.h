#pragma once
#include "src/CommonHeaders.h"

#include "EngineState.h"
#include "Sprite.h"

NamespaceScarlettBegin

class Engine
{
public:
	void StartEngine();

	void Run();

	void DestroyEngine();
private:
	SDL_Window* m_window = nullptr;
	EngineState m_state = EngineState::Loading;
	int m_width = 1024;
	int m_height = 768;
	void Render();
};

NamespaceScarlettEnd