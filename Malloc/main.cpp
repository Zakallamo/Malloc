#include "MemoryAllocator.h"
#include "StackAllocator.h"
#include "PoolAllocator.h"
#include "OSAllocator.h"
#include "TestSystem.h"

int main()
{
	// Test that the allocators are creatable
	/*delete new MemoryAllocator<StackAllocator>();
	delete new MemoryAllocator<PoolAllocator>();
	MemoryAllocator<OSAllocator>* mall = new MemoryAllocator<OSAllocator>();
	void* test = mall->Allocate<int>();
	if(test==nullptr)
		int i = 0;
	mall->Free(test);
	delete mall;*/

	TestSystem<MemoryAllocator<OSAllocator>> test;
	test.Initialize(test.SCENARIO2, 10000, 1);
	test.Run();
}