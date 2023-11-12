#pragma once

namespace Scarlett {

/***
=========================================================================================
WINDOW_PROPERTIES:
	Structure holding the properties for a window.
=========================================================================================
*/
struct WindowProperties
{
	WindowProperties(const std::string& title = "Scarlett Engine", uint16 width = 1280, uint16 height = 720) :
		title(title),
		width(width),
		height(height)
	{
		// Empty.
	}

	std::string title;
	uint16 width, height;
};

/***
=========================================================================================
WINDOW:
	A window interface to handle the engines Window regardless of API.
	Creating new winow type:
		Inherit from this class and override all the methods.
		In new API cpp file:

			#if API == 1
			Window* Window::Create() 
			{ 
				return new API_Window(properties); 
			}
			#endif
=========================================================================================
*/
class Window
{
public:
	virtual ~Window() { }

	static Window* Create(const WindowProperties& properties = WindowProperties());

	virtual void Update() = 0;

	// Accessors.
	virtual uint16 GetWidth()	const = 0;
	virtual uint16 GetHeight()	const = 0;

	// Mutators.
	// TODO (Christain): Make the window resizable.
	virtual void Resize(uint16 width, uint16 height) = 0;
};
} // Scarlett Namespace.