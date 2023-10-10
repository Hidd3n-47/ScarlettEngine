#pragma once

#include "CommonHeaders.h"


NamespaceScarlettBegin

struct MemoryData
{
	uint32 allocated = 0;
	uint32 freed = 0;
};

class MemoryManager
{
public:
	void* operator new (size_t size)
	{
		m_memoryAllocationData.allocated += size;

		return malloc(size);
	}

	void operator delete(void* memory, size_t size)
	{
		m_memoryAllocationData.freed += size;
		free(memory);
	}

	void PrintMemoryAllocation()
	{
		std::cout << "|===================================================================|\n";
		std::cout << "|                          MEM_ALLOCATION                           |\n";
		std::cout << "|-------------------------------------------------------------------|\n";
		std::cout << "| Allocated: " << m_memoryAllocationData.allocated << " bytes\n";
		std::cout << "| Freed: " << m_memoryAllocationData.freed << " bytes\n";
		std::cout << "|===================================================================|\n";
	}

private:
	static MemoryData m_memoryAllocationData;
};

NamespaceScarlettEnd