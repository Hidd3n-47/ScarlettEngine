#include "sltpch.h"
#include "SDLWindow.h"

namespace Scarlett {

#if SDL_API == 1
Window* Window::Create(const WindowProperties& properties)
{
	return new SDLWindow(properties);
}
#endif

SDLWindow::SDLWindow(const WindowProperties& properties) :
	m_title(properties.title),
	m_width(properties.width),
	m_height(properties.height)
{
	Init();
}

SDLWindow::~SDLWindow()
{
	Destroy();
}

void SDLWindow::Update()
{
	// Update double buffer and poll input.
}

void SDLWindow::Init()
{
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_windowHandle = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	SDL_GLContext glContext = SDL_GL_CreateContext(m_windowHandle);

	DLOG("Created window: " + m_title + " " + std::to_string(m_width) + " x " + std::to_string(m_height));
}

void SDLWindow::Destroy()
{
	SDL_DestroyWindow(m_windowHandle);
}

} // Scarlett Namespace.