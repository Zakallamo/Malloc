#include "StackAllocator.h"
#include "PoolAllocator.h"
#include "OSAllocator.h"

int main()
{
	// Test that the allocators are creatable
	delete new StackAllocator();
	delete new PoolAllocator();
	OSAllocator* mall = new OSAllocator();
	void* test = mall->Allocate<int>();
	if(test==nullptr)
		int i = 0;
	mall->Free(test);
	delete mall;
}