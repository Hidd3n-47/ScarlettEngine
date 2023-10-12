#pragma once

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>

#include <sdl/sdl.h>
#include <gl/glew.h>

#include "CustomMacros.h"

#include "PrimativeTypes.h"

struct MemoryStruct
{
	uint32 allocated;
	uint32 freed;
};

static MemoryStruct MEM_ALLOCATION;

inline void* operator new (size_t size)
{
	MEM_ALLOCATION.allocated += (uint32)size;

	return malloc(size);
}

inline void operator delete(void* memory, size_t size)
{
	MEM_ALLOCATION.freed += (uint32)size;
	free(memory);
}

static inline void PrintMemoryAllocation()
{
	std::cout << "|===================================================================|\n";
	std::cout << "|                          MEM_ALLOCATION                           |\n";
	std::cout << "|-------------------------------------------------------------------|\n";
	std::cout << "| Allocated: " << MEM_ALLOCATION.allocated << " bytes\n";
	std::cout << "| Freed: " << MEM_ALLOCATION.freed << " bytes\n";
	std::cout << "|===================================================================|\n";
}