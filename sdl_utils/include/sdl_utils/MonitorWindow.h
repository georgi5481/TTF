#ifndef SDL_UTILS_MONITORWINDOW_H_
#define SDL_UTILS_MONITORWINDOW_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<string>
//3rd-party includes

//Own includes
#include "utils/drawings/Rectangle.h"
#include "sdl_utils/config/MonitorWindowCfg.h"

//Forward Declaration
struct SDL_Window;
struct SDL_Surface;	//declaring these just so we can create void pointers to a struct/class

class MonitorWindow {
public:
	MonitorWindow() = default;
	 ~MonitorWindow();

	MonitorWindow(const MonitorWindow& other) = delete;
	//deleting the copy constructor cuz we cant have 2 monitor-screens of our application

	MonitorWindow(MonitorWindow&& other) = delete;
	//deleting the move constructor

	MonitorWindow& operator=(const MonitorWindow& other) = delete; //delete copy/assignment constructor
	MonitorWindow& operator=(MonitorWindow&& other) = delete;	//delete the move constructor

	int32_t init(const MonitorWindowCfg& cfg);
	void deinit();


	void updateWindowSurface();

	SDL_Window* getWindow();

private:
	SDL_Window* _window = nullptr;
	Rectangle _windowRect = Rectangle::UNDEFINED;
};

#endif /* SDL_UTILS_MONITORWINDOW_H_ */
