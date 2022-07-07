#ifndef SDL_UTILS_CONFIG_MONITORWINDOWCFG_H_
#define SDL_UTILS_CONFIG_MONITORWINDOWCFG_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<string>
//3rd-party includes

//Own includes
#include "utils/drawings/Point.h"

//Forward Declaration

enum WindowFlags{	//these concrete numbers comes from the SDL flags
	WINDOW_SHOWN = 4,			//SDL_WindowShown
	WINDOW_FULLSCREEN = 4097,	//SDL_WindowFullscreen
	WINDOW_BORDERLESS = 16,		//Make the same window but without borders
	WINDOW_RESIZABLE = 32
};

struct MonitorWindowCfg{
	 std::string windowName;
	 Point windowPosition = Point::UNDEFINED;
	 int32_t windowWidth = 0;
	 int32_t windowHeight = 0;
	 WindowFlags windowFlags = WINDOW_SHOWN;
};




#endif /* SDL_UTILS_CONFIG_MONITORWINDOWCFG_H_ */
