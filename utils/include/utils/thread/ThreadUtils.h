#ifndef UTILS_THREAD_THREADUTILS_H_
#define UTILS_THREAD_THREADUTILS_H_

//C system includes

//C++ system includes
#include<cstdint>
//3rd-party includes

//Own includes

//Forward Declaration

class ThreadUtils {
public:
	ThreadUtils() = delete;
	static void sleepFor(int64_t microseconds);
};

#endif /* UTILS_THREAD_THREADUTILS_H_ */
