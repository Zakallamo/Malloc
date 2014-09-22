#pragma once
#include "MemoryAllocator.h"

class PoolAllocator : public MemoryAllocator
{
public:
	void Initialize( uint64_t p_size ) {}
	void Destroy() {}
	void* Allocate( uint64_t p_size ) { return nullptr; }
	void* AllocateAligned( uint64_t p_size, uint8_t p_alignment ) { return nullptr; }
	void Free( void* p_pointer ) {}
	void FreeAligned( void* p_pointer ) {}
	void FreeAll( ) {}
};