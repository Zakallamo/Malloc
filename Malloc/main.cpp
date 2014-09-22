#include "StackAllocator.h"
#include "PoolAllocator.h"
#include "OSAllocator.h"

int main()
{
	// Test that the allocators are creatable
	delete new StackAllocator();
	delete new PoolAllocator();
	delete new OSAllocator();
}