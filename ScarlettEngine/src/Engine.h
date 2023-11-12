#pragma once

#include "Window/Window.h"
#include "Input/InputManager.h"

namespace Scarlett {
class Engine
{
public:
	inline static Engine* Instance() { return m_instance == nullptr ? m_instance = new Engine() : m_instance; }

	void Init();

	void Run();

	void Destroy();

	inline void StopRunning() { m_running = false; Destroy(); }
private:
	static Engine* m_instance;

	std::unique_ptr<Window> m_window;
	std::unique_ptr<InputManager> m_input;

	bool m_running = true;
};
}
