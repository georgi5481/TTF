//Corresponding header
#include "utils/thread/ThreadUtils.h"
//C system includes

//C++ system includes
#include<cstdint>
#include<thread>
//3rd-party includes

//Own includes

#ifdef _WIN32				//this class is usefull for multi-platform implementation for sleep
#include<windows.h>
#else
#include<thread>
#endif

void ThreadUtils::sleepFor(int64_t microseconds){
#ifdef _WIN32
	const DWORD milliseconds = static_cast<DWORD>(micoseconds/1000);
	Sleep(milliseconds); //sleep for milliseconds
#else
	std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
#endif
}
