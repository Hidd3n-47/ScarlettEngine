#include "CommonHeaders.h"
#include "Engine.h"

int main(int argc, char** argv)
{
	//PrintMemoryAllocation();

	Scarlett::Engine eng;

	eng.StartEngine();
	eng.Run();
	eng.DestroyEngine();


	//PrintMemoryAllocation();

	//system("PAUSE");
	return 0;
}