#ifndef UTILS_TIME_TIME_H_
#define UTILS_TIME_TIME_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<chrono>

//3rd-party includes

//Own includes


class Time {
public:
	void init();
	//getElapsed() method simply mesures time between 2 points of time
	Time& getElapsed();

	int64_t toSeconds()const;			//	will get the time elapsed since the last call
	int64_t toMilliseconds() const;		// 1s = 10^3
	int64_t  toMicroseconds() const;	// 1s = 10^6
	int64_t  toNanoseconds() const;		// 1s = 10^9

std::chrono::time_point<std::chrono::steady_clock> _now = std::chrono::steady_clock::now();
			//for storing the current time atm

std::chrono::time_point<std::chrono::steady_clock> _elapsedLastCall;
			//for storing the time elapsed
};

#endif /* UTILS_TIME_TIME_H_ */
