#pragma once

#include <cstdint> // int, uint 32 and 64 types

class MemoryAllocator abstract
{
public:
	MemoryAllocator() : isInitialized(false) {}

	virtual void Initialize( uint64_t p_size ) = 0;
	virtual void Destroy() = 0;
	virtual void* Allocate( uint64_t p_size ) = 0;
	virtual void* AllocateAligned( uint64_t p_size, uint8_t p_alignment ) = 0;
	virtual void Free( void* p_pointer ) = 0;
	virtual void FreeAligned( void* p_pointer ) = 0;
	virtual void FreeAll( ) = 0;

private:

	bool isInitialized;
};