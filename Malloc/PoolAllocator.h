#pragma once

// Decide whether or not to template this implementation to allow only a specific type of objects to occupy the memory pool
//template<typename T>
class PoolAllocator
{
public:
	void Initialize( uint64_t p_size )
	{
		// Initialize a memory pool equal to p_size bytes
	}
	void Destroy()
	{
		// Free the memory pool
	}

	template<typename T>
	void* Allocate( uint64_t p_size )
	{
		// Check the requested object's type to match the memory pool structure or assume a match
		// Return a pointer to the first free memory within the pool and mark that memory as occupied
		return nullptr;
	}
	template<typename T>
	void* AllocateAligned( uint64_t p_size, uint8_t p_alignment )
	{
		// Check the memory chapter for this
		// Not sure if we need to implement this to pass
		return nullptr;
	}

	void Free( void* p_pointer )
	{
		// Simply mark the memory the pointer points to within the pool as free again
	}
	void FreeAligned( void* p_pointer )
	{
		// Check the comments for AllocateAligned
	}
	void FreeAll( )
	{
		// Mark all memory as free
		// Not sure if necessary
	}
};