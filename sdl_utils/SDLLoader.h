#ifndef SDL_UTILS_SDLLOADER_H_
#define SDL_UTILS_SDLLOADER_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

//Forward Declaration

class SDLLoader {
public:
	SDLLoader() = delete;
	~SDLLoader() = default;

	static int32_t init();

	static void deinit();
};

#endif /* SDL_UTILS_SDLLOADER_H_ */
