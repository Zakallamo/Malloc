#pragma once

class StackAllocator
{
public:
	void Initialize( uint64_t p_size ) {}
	void Destroy() {}

	template<typename T>
	void* Allocate( ) { return nullptr; }
	template<typename T>
	void* AllocateAligned( uint8_t p_alignment ) { return nullptr; }

	void Free( void* p_pointer ) {}
	void FreeAligned( void* p_pointer ) {}
	void FreeAll( ) {}
};