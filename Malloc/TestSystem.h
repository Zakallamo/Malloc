/*
	Implementation in this file can not be split into .cpp because of the use of template as a defining part of the class. C++ compilers, Y U do this?!
*/
#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "MemoryAllocator.h"
#include <algorithm>    // std::shuffle
#include <vector>        // std::vector
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

template<class T>
class TestSystem
{
public:
	enum Scenario { NOTINITIALIZED, SCENARIO1, SCENARIO2 };

	TestSystem() : memoryAllocator( new T( ) ), scenario( NOTINITIALIZED ) { }

	void Initialize( Scenario p_scenario, int p_maxObjects, int p_frameCount )
	{
		scenario = p_scenario;
		maxObjects = p_maxObjects;
		frameCount = p_frameCount;
	}

	void Run( int p_times = 100 )
	{
		__int64 startTime, endTime, totalTime = 0, minTime = INT64_MAX, maxTime = 0, tempTime;

		__int64 qfreq;
		QueryPerformanceFrequency((LARGE_INTEGER*)&qfreq);
		double dFreq = (double)qfreq/1000.0;
		
		std::cout << "Running test " << p_times << " times..." << std::endl;

		for(int currentRun = 0; currentRun < p_times; ++currentRun)
		{
			// Initialize the scenario
			switch(scenario)
			{
			case SCENARIO1:
				InitializeScenario1( );
				break;
			case SCENARIO2:
				InitializeScenario2( );
				break;
			case NOTINITIALIZED:
				std::cout << "Error: Test System not initialized";
			}

			QueryPerformanceCounter((LARGE_INTEGER*)&startTime);

			// Call the scenario
			switch(scenario)
			{
			case SCENARIO1:
				Scenario1( );
				break;
			case SCENARIO2:
				Scenario2( );
				break;
			case NOTINITIALIZED:
				std::cout << "Error: Test System not initialized";
			}

			QueryPerformanceCounter((LARGE_INTEGER*)&endTime);

			tempTime = endTime - startTime;
			if(tempTime < minTime)
				minTime = tempTime;
			if(tempTime > maxTime)
				maxTime = tempTime;
			totalTime += tempTime;
			
			// Destroy the scenario
			switch(scenario)
			{
			case SCENARIO1:
				DestroyScenario1( );
				break;
			case SCENARIO2:
				DestroyScenario2( );
				break;
			case NOTINITIALIZED:
				std::cout << "Error: Test System not initialized";
			}
		}
		
		std::cout << "Avg time: " << totalTime/dFreq/p_times << "ms" << std::endl;
		std::cout << "Min time: " << minTime/dFreq << "ms" << std::endl;
		std::cout << "Max time: " << maxTime/dFreq << "ms" << std::endl;
		std::cout << "Total time: " << totalTime/dFreq << "ms" << std::endl;
		char c;
		std::cin.get(c);
	}

private:
	void InitializeScenario1( )
	{
		memoryList.resize( maxObjects );

		// obtain a time-based seed:
		//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		seed = 1337; // Not so random!
	}
	void Scenario1( )
	{
		// Allocate memory if needed
		memoryAllocator->Initialize(1000*sizeof(uint64_t));

		int numObjects = 0;
		int i = 0, j = 0;
		for(i = 0; i < frameCount; ++i)
		{
			for(j = numObjects; j < max(maxObjects, maxObjects * 0.5f + numObjects * 0.5f); ++j)
			{
				// Save the memory addresses to be able to free them later
				memoryList[j] = (uint64_t)memoryAllocator->Allocate<uint64_t>( );
				*(uint64_t*)(memoryList[j]) = j;
			}
			numObjects = j;
			// Do something with the objects
			
			// Shuffle memoryList to free random elements
			shuffle(memoryList.begin(), memoryList.begin() + j, std::default_random_engine(seed));

			// Free half of the objects
			for(j = numObjects / 2; j < numObjects; ++j)
			{
				memoryAllocator->Free( (void*)memoryList[j] );
				memoryList[j] = 0;
			}
			numObjects /= 2;
		}
		for(j = 0; j < numObjects; ++j)
		{
			memoryAllocator->Free( (void*)memoryList[j] );
		}
	}
	void DestroyScenario1( )
	{
		memoryList.clear();
	}

	void InitializeScenario2( )
	{
	}
	void Scenario2( )
	{

	}
	void DestroyScenario2( )
	{
	}

	unsigned seed;
	int maxObjects, frameCount;
	Scenario scenario;
	T* memoryAllocator;
	std::vector<uint64_t> memoryList;
};