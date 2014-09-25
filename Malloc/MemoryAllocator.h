#pragma once

#include <cstdint> // int, uint 32 and 64 types

class MemoryAllocator abstract
{
public:
	MemoryAllocator() : isInitialized(false) {}

	virtual void Initialize( uint64_t p_size ) = 0;
	virtual void Destroy() = 0;
	
	// Implement a function which checks the type of "this" and call the according function because template and virtual aren't friends
	template<class T>
	void* Allocate( typename p_type );
	template<class T>
	void* AllocateAligned( typename p_type, uint8_t p_alignment );

	virtual void Free( void* p_pointer ) = 0;
	virtual void FreeAligned( void* p_pointer ) = 0;
	virtual void FreeAll( ) = 0;

private:

	bool isInitialized;
};