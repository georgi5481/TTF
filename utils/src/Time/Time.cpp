//Corresponding header
#include "utils/Time/Time.h"

//C system includes

//C++ system includes
#include<thread>

//3rd-party includes

//Own includes

Time& Time::getElapsed(){		//clever way of setting the time
	_elapsedLastCall = _now;	//this will set 'the elapsed time' equal to the the previous _now
	_now = std::chrono::steady_clock::now();		//this will set the time atm.
	return *this;
}

int64_t Time::toSeconds() const {
	return std::chrono::duration_cast<std::chrono::seconds>
					(_now - _elapsedLastCall).count();
}				/*first we take off (now time - elapsed call)
				  so that we can get the time space between them

				  second we cast this time into what we want(seconds, micro/macro/nano seconds etc.)

				  and third we call the method count()*/


int64_t Time::toMilliseconds() const{
	return std::chrono::duration_cast<std::chrono::milliseconds>
					(_now - _elapsedLastCall).count();
}

int64_t  Time::toMicroseconds() const	{
	return std::chrono::duration_cast<std::chrono::microseconds>
					(_now - _elapsedLastCall).count();
}

int64_t  Time::toNanoseconds() const{
	return std::chrono::duration_cast<std::chrono::nanoseconds>
					(_now - _elapsedLastCall).count();
}





