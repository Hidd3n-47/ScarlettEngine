#pragma once

#include <sdl/SDL.h>

#include "Window.h"

namespace Scarlett {
/***
=========================================================================================
SDL_WINDOW:
	A window created using SDL API.
=========================================================================================
*/
class SDLWindow : public Window
{
public:
	SDLWindow(const WindowProperties& properties);
	virtual ~SDLWindow();

	virtual void Update() override;

	// Accessors.
	inline virtual uint16 GetWidth()	const override { return m_width; }
	inline virtual uint16 GetHeight()	const override { return m_height; }

	inline virtual void Resize(uint16 width, uint16 height) override { m_width = width; m_height = height; DLOG("Window resized to: " + std::to_string(width) + " x " + std::to_string(height)); }
private:
	std::string m_title;
	uint16 m_width, m_height;

	SDL_Window* m_windowHandle;

	virtual void Init();
	virtual void Destroy();
};
} // Scarlett Namespace.
