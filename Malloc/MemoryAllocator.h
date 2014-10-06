#pragma once

#include <cstdint> // int, uint 32 and 64 types

template<class T>
class MemoryAllocator
{
public:
	MemoryAllocator() : isInitialized(false), allocator( new T() ) { }
	~MemoryAllocator() { delete allocator; }

	void Initialize( uint64_t p_size ) { allocator->Initialize( p_size ); }
	void Destroy() { allocator->Destroy( ); }
	
	// Implement a function which checks the type of "this" and call the according function because template and virtual aren't friends
	template<typename T>
	void* Allocate( ) { return allocator->Allocate<T>( ); }
	template<typename T>
	void* AllocateAligned( uint8_t p_alignment ) { return allocator->AllocateAligned<T>( ); }

	void Free( void* p_pointer ) { allocator->Free( p_pointer ); }
	void FreeAligned( void* p_pointer ) { allocator->FreeAligned( p_pointer ); }
	void FreeAll( ) { allocator->FreeAll(  ); }

private:

	bool isInitialized;
	T* allocator;
};