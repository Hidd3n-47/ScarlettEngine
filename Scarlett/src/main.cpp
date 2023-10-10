#include "Engine.h"

int main(int argc, char** argv)
{
	Scarlett::Engine eng;

	eng.StartEngine();
	eng.Run();
	eng.DestroyEngine();

	return 0;
}