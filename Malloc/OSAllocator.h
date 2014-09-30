#pragma once

// Passes all the calls through to the OS memory management calls
class OSAllocator
{
public:
	void Initialize( uint64_t p_size ) {}
	void Destroy() {}

	template<typename T>
	void* Allocate( ) { return new T(); }
	template<typename T>
	void* AllocateAligned( uint8_t p_alignment ) { return Allocate<T>( ); /* ToDo: Implement alignment */ }

	void Free( void* p_pointer ) { delete p_pointer; }
	void FreeAligned( void* p_pointer ) { delete p_pointer; /* ToDo: Implement alignment */ }
	void FreeAll( ) { /* Should this exist for OSAllocator? */ }
};