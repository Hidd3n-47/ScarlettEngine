#include "sltpch.h"

#include "Engine.h"

int main(int argc, char** argv)
{
	Scarlett::Engine engine;

	engine.Init();
	engine.Run();
	engine.Destroy();

	return 0;
}