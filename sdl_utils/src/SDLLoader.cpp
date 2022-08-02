//Corresponding header
#include "sdl_utils/SDLLoader.h"

//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>

//3rd-party includes
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

//Own includes
#include "sdl_utils/SDLLoader.h"

int32_t SDLLoader::init(){
	if(EXIT_SUCCESS != TTF_Init())
	{
		std::cerr << "SDL_Init failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO))
	{
		std::cerr << "SDL_Init failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	constexpr int32_t imgFlags = IMG_INIT_PNG;
	if(! (IMG_Init(imgFlags) & imgFlags)){
		std::cerr << "SDL image could not be initialised! SDL_masage Error:" <<
				IMG_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if(0 > Mix_OpenAudio(44100,//sound frequency
			MIX_DEFAULT_FORMAT,//sample format
			2,					//stereo hardware channels
			2048)){				//chunk size
		std::cerr << "SDL_mixer could not be initialised! SDL Error: " <<
				Mix_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
void SDLLoader::deinit(){
	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();
}
