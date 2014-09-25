#pragma once
#include "MemoryAllocator.h"

class StackAllocator : public MemoryAllocator
{
public:
	void Initialize( uint64_t p_size ) {}
	void Destroy() {}

	template<class T>
	void* Allocate( ) { return nullptr; }
	template<class T>
	void* AllocateAligned( uint8_t p_alignment ) { return nullptr; }

	void Free( void* p_pointer ) {}
	void FreeAligned( void* p_pointer ) {}
	void FreeAll( ) {}
};